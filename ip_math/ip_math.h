#ifndef _IP_MATH_H_
#define _IP_MATH_H_

#include <stdint.h>

void get_broadcast_addr(const char *ip_addr, char mask, char *broadcast_addr);
uint32_t get_addr_integer_equivalent(const char *addr_str);
void get_addr_str_format(const uint32_t addr_int, char *output_buf);
void get_network_id(const char *ip_addr_str, const uint8_t mask_cidr, char *nwk_id_str);
void get_subnet_cardinality(const char mask);
int is_subnet_membership(const char *nwk_id, const char mask, const char *check_ip);

#endif // _IP_MATH_H_