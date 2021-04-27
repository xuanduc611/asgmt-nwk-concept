#include <stdio.h>
#include "./ip_math/ip_math.h"

int main(int argc, char **argv)
{
    char str[100];
    unsigned int ip;

    get_str_ip_format(3232235892, str);
    printf("Test get_str_ip_format: %s\n", str);

    ip = get_ip_integer_equivalent("192.168.1.116");
    printf("Test get_ip_integer_equivalent: %u\n", ip);

    return 0;
}
