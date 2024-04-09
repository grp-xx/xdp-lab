#include <iostream>
#include <cstdlib> 
#include <bpf/bpf.h>
#include <xdp/libxdp.h>
#include <linux/if_ether.h>
#include <xdp/xdp_helpers.h>
#include <iproute2/bpf_elf.h>
#include <net/if.h>

#define IFINDEX 2


int main(int argc, char** argv)
{
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    int n = if_nametoindex(argv[1]);

    int id = atoi(argv[2]);

    std::cout << "IFINDEX: " << n << std::endl;
    struct xdp_program *p = xdp_program__from_id(id);
    
    std::cout << "Program name: " << xdp_program__name(p) << std::endl;

}