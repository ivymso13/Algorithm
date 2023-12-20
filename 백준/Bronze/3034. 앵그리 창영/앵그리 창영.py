N, W, H = map(int, input().split())
for _ in range(N):
    t = int(input())

    if t*t > W*W+H*H:
        print("NE")
    else:
        print("DA")