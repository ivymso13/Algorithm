N = int(input())
inp = list(map(int, input().split()))

inp.sort()

if N == 1:
    print(inp[0])
else:
    if N%2 > 0:
        inp.pop(N-1)
        N -= 1
    
    ret = inp[0] + inp[-1]
    for i in range(1, N//2):
        ret = max(ret, inp[i] + inp[N-i-1])

    print(ret)