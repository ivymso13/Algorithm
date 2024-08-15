a = int(input())
b = int(input())
ret = 2

while a>=b:
    a, b = b, abs(a-b)
    ret += 1

print(ret)