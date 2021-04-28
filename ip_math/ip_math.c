#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ip_math.h"

void get_broadcast_addr(const char *ip_addr, char mask, char *broadcast_addr)
{;}

unsigned int get_addr_integer_equivalent(const char *addr_str)
{
    unsigned char ip_byte[4];

    sscanf(addr_str, "%hhu.%hhu.%hhu.%hhu", &ip_byte[3], &ip_byte[2], &ip_byte[1], &ip_byte[0]);

    return ((ip_byte[3] << 24) | (ip_byte[2] << 16) | (ip_byte[1] << 8) | ip_byte[0]);
}

void get_addr_str_format(const unsigned int addr_int, char *output_buf)
{
    sprintf(output_buf, "%d.%d.%d.%d", (addr_int & 0xFF000000) >> 24, \
                                        (addr_int & 0xFF0000) >> 16, \
                                        (addr_int & 0xFF00) >> 8, \
                                        (addr_int & 0xFF));
}

void get_network_id(const char *ip_addr_str, const char mask_cidr, char *nwk_id_str)
{
    unsigned int ip_addr_int, nwk_id_int;
    unsigned int mask;

    mask = 0xFFFFFFFF << (32 - mask_cidr);
    ip_addr_int = get_addr_integer_equivalent(ip_addr_str);
    nwk_id_int = ip_addr_int & mask;

    get_addr_str_format(nwk_id_int, nwk_id_str);
}

void get_subnet_cardinality(const char mask)
{;}

int is_subnet_membership(const char *nwk_id, const char mask, const char *check_ip)
{return 1;}