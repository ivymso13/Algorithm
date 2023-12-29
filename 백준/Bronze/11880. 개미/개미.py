T = int(input())
while T > 0:
    a, b, c = map(int, input().split())

    tot = a+b+c
    m = max(a, b, c)

    print((tot-m)**2 + m**2)
    
    T -= 1