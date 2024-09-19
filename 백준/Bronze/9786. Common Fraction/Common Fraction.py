N = int(input())

def getGCD(a, b):
    if a<b:
        return getGCD(b, a)
    else:
        if b == 0:
            return a
        else:
            return getGCD(b, a%b)

for i in range(N):
    a, b = map(int, input().split())

    gcd = getGCD(a, b)
    print(a//gcd, b//gcd)