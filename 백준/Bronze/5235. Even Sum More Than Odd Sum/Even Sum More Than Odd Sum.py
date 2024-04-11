T = int(input())

for _ in range(T):
    inp = list(map(int, input().split()))

    even, odd = 0, 0
    for i in range(1, inp[0]+1):
        if inp[i]%2 == 1:
            odd += inp[i]
        else:
            even += inp[i]

    if even > odd:
        print("EVEN")
    elif even < odd:
        print("ODD")
    else:
        print("TIE")