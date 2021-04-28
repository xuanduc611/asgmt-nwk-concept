#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "ip_math.h"

void get_broadcast_addr(const char *ip_addr_str, const uint8_t mask_cidr, char *broadcast_addr_str)
{
    char nwk_id_str[20];
    uint32_t nwk_id_int;
    uint32_t mask;
    uint32_t broadcast_addr_int;

    // Get nwk_id:
    get_network_id(ip_addr_str, mask_cidr, nwk_id_str);
    nwk_id_int = get_addr_integer_equivalent(nwk_id_str);

    // Get mask:
    mask = 0xFFFFFFFF << (sizeof(uint32_t) * __CHAR_BIT__ - mask_cidr);
    broadcast_addr_int = nwk_id_int | (~mask);
    get_addr_str_format(broadcast_addr_int, broadcast_addr_str);
}

uint32_t get_addr_integer_equivalent(const char *addr_str)
{
    uint8_t ip_byte[4];

    sscanf(addr_str, "%hhu.%hhu.%hhu.%hhu", &ip_byte[3], &ip_byte[2], &ip_byte[1], &ip_byte[0]);

    return ((ip_byte[3] << 24) | (ip_byte[2] << 16) | (ip_byte[1] << 8) | ip_byte[0]);
}

void get_addr_str_format(const uint32_t addr_int, char *output_buf)
{
    sprintf(output_buf, "%d.%d.%d.%d", (addr_int & 0xFF000000) >> 24, \
                                        (addr_int & 0xFF0000) >> 16, \
                                        (addr_int & 0xFF00) >> 8, \
                                        (addr_int & 0xFF));
}

void get_network_id(const char *ip_addr_str, const uint8_t mask_cidr, char *nwk_id_str)
{
    uint32_t ip_addr_int, nwk_id_int;
    uint32_t mask;
    mask = 0xFFFFFFFF << (sizeof(uint32_t) * __CHAR_BIT__ - mask_cidr);
    ip_addr_int = get_addr_integer_equivalent(ip_addr_str);
    nwk_id_int = ip_addr_int & mask;

    get_addr_str_format(nwk_id_int, nwk_id_str);
}

uint32_t get_subnet_cardinality(const char mask_cidr)
{
    return (uint32_t)(pow(2, 32 - mask_cidr) - 2);
}

int is_subnet_membership(const char *src_nwk_id_str, const char mask_cidr, const char *check_ip_str)
{
    char check_nwk_id_str[20];
    int result;

    // Get check_nwk_id:
    get_network_id(check_ip_str, mask_cidr, check_nwk_id_str);

    // Compare:
    result = strcmp(src_nwk_id_str, check_nwk_id_str);
    
    if (result == 0) {
        return 1;
    } else {
        return 0;
    }
}