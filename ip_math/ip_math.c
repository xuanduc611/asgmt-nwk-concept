#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ip_math.h"

void get_broadcast_addr(const char *ip_addr, char mask, char *broadcast_addr)
{;}

unsigned int get_ip_integer_equivalent(const char *ip_addr_str)
{
    unsigned char ip_byte[4];

    sscanf(ip_addr_str, "%hhu.%hhu.%hhu.%hhu", &ip_byte[3], &ip_byte[2], &ip_byte[1], &ip_byte[0]);

    return ((ip_byte[3] << 24) | (ip_byte[2] << 16) | (ip_byte[1] << 8) | ip_byte[0]);
}

void get_str_ip_format(const unsigned int ip_addr_int, char *output_buf)
{
    sprintf(output_buf, "%d.%d.%d.%d", (ip_addr_int & 0xFF000000) >> 24, \
                                        (ip_addr_int & 0xFF0000) >> 16, \
                                        (ip_addr_int & 0xFF00) >> 8, \
                                        (ip_addr_int & 0xFF));
}

void get_network_id(const char *ip_addr, const char mask, char *output_buf)
{;}

void get_subnet_cardinality(const char mask)
{;}

int is_subnet_membership(const char *nwk_id, const char mask, const char *check_ip)
{return 1;}