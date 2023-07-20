#include <iostream>
#include <cstdlib> 
#include <bpf/bpf.h>
#include <xdp/libxdp.h>
#include <linux/if_ether.h>
// #include <bpf/bpf_helpers.h>
#include <xdp/xdp_helpers.h>
#include <iproute2/bpf_elf.h>


#define IFINDEX 2


int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    struct xdp_program *p = xdp_program__from_id(n); 

}