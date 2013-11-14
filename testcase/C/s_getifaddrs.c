#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>

int main(int argc, const char *argv[])
{
    struct ifaddrs *ifap;
    struct ifaddrs *ifa;


    getifaddrs(&ifap);

    for (ifa=ifap; ifa; ifa=ifa->ifa_next) {
        printf("\nifa_name[%s] \n", ifap->ifa_name);
        printf("\nifa_flags %d \n", ifap->ifa_flags);
        printf("\nifa_addr %s \n", ifap->ifa_addr->sa_data);
    }
    
    return 0;
}
