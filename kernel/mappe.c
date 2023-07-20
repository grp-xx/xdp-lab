#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <bpf/bpf_helpers.h>
#include <iproute2/bpf_elf.h>

SEC("maps")
struct bpf_elf_map state_map = {
	.type        = BPF_MAP_TYPE_ARRAY,
	.size_key    = sizeof(__u32),
	.size_value  = sizeof(__u32),
	.max_elem    = 2,
};
BPF_ANNOTATE_KV_PAIR(state_map, __u32, __u32);  // Print in json "human readable" format

SEC("prog")
int  count_n(struct xdp_md *ctx)
{
	void *data_end = (void *)(long)ctx->data_end;
	void *data     = (void *)(long)ctx->data;
	struct ethhdr *hdr;
	__u32 key = 0;
	__u32 *count;

	if (data + sizeof(struct ethhdr) <= data_end) 
	{
		hdr = data;
		key = hdr->h_source[0] & 1;

		count = bpf_map_lookup_elem(&state_map, &key);
		if (!count)
			return XDP_ABORTED;

		__sync_fetch_and_add(count, 1);
	}

	return XDP_PASS;
}

SEC("license") 
char _license[]= "GPL";