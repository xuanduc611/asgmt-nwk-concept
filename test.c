#include <stdio.h>
#include <stdint.h>
#include "ip_math.h"

int main(int argc, char **argv)
{
    char str[100];
    uint32_t ip;
    uint32_t max;
    int ret;

    get_addr_str_format(3232235892, str);
    printf("Test get_str_ip_format(): %s\n", str);

    ip = get_addr_integer_equivalent("192.168.1.116");
    printf("Test get_ip_integer_equivalent(): %u\n", ip);

    get_network_id("192.168.15.116", 24, str);
    printf("Test get_network_id(): %s\n", str);

    get_broadcast_addr("192.168.15.116", 24, str);
    printf("Test get_broadcast_addr(): %s\n", str);

    max = get_subnet_cardinality(24);
    printf("Test get_subnet_cardinality(): %d\n", max);

    ret = is_subnet_membership("192.168.15.0", 24, "192.168.15.116");
    printf("Test is_subnet_membership(): %d\n", ret);
    return 0;
}
