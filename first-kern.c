#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>


SEC("mydrop")
int my_drop(struct xdp_md *ctx)
{
    return XDP_DROP;
}

SEC("mypass")
int my_pass(struct xdp_md *ctx)
{
    return XDP_PASS;
}

char _license[] SEC("license") = "GPL";

