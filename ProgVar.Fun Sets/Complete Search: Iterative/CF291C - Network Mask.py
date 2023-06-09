n, k = [int(x) for x in input().split()]
arr = [input() for _ in range(n)]

# ip to mask
arr_masks = []
for x in arr:
    arr_list = [bin(int(y))[2:].zfill(8) for y in x.split('.')]
    arr_masks.append(int(''.join(arr_list),2))

# mask to ip
def mask_to_ip(mask):
    binary = bin(mask)[2:].zfill(32)
    a, b, c, d = binary[:8], binary[8:16], binary[16:24], binary[24:]
    ip_list = [int(a,2), int(b,2), int(c,2), int(d,2)]
    return '.'.join([str(x) for x in ip_list])

for i in range(1,32):
    mask_list = ["0"]*32
    for j in range(i):
        mask_list[j] = "1"
    
    mask = int(''.join(mask_list),2)
    
    networks = []
    for x in arr_masks:
        networks.append(mask&x)
    
    if len(set(networks)) == k:
        print(mask_to_ip(mask))
        exit()

print(-1)
