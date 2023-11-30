N, S = map(int, input().split())
inp = [abs(S-int(t)) for t in input().split()]


def getGCD(a, b):
    if a<b:
        return getGCD(b, a)
    return a if b==0 else getGCD(b, a%b)

gcd = inp[0]
for i in range(1, N):
    gcd = getGCD(gcd, inp[i])

print(gcd)