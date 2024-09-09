a, b, n = map(int, input().split())

def getGCD(x, y):
    if x<y:
        return getGCD(y, x)
    else:
        if y == 0:
            return x
        else:
            return getGCD(y, x%y)

lcm = a*b//getGCD(a, b)

ans = n//a + n//b
if lcm > 1:
    ans -= n//lcm

print(ans)