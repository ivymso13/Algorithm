D, H, W = map(int, input().split())

t = (D*D / (H*H + W*W))**0.5

print(int(t*H), int(t*W))