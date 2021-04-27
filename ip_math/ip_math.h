#ifndef _IP_MATH_H_
#define _IP_MATH_H_

void get_broadcast_addr(const char *ip_addr, char mask, char *broadcast_addr);
unsigned int get_ip_integer_equivalent(const char *ip_addr_str);
void get_str_ip_format(const unsigned int ip_addr_int, char *output_buf);
void get_network_id(const char *ip_addr, const char mask, char *output_buf);
void get_subnet_cardinality(const char mask);
int is_subnet_membership(const char *nwk_id, const char mask, const char *check_ip);

#endif // _IP_MATH_H_