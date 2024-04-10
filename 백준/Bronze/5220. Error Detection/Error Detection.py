T = int(input())

for _ in range(T):
    N, f = map(int, input().split())

    cnt = 0
    while N>0:
        cnt += N%2
        N //= 2
    
    if (cnt+f)%2 == 0:
        print("Valid")
    else:
        print("Corrupt")
    