N = int(input())

check = [""]*36
number = []
for i in range(10):
    number.append(str(i))
for i in range(26):
    number.append(chr(i+65))

def add(a, b):
    a, b = a[::-1], b[::-1]
    if len(a) < len(b):
        a, b = b, a

    f = 0
    ret = ""
    for i in range(len(a)):
        if i < len(b):
            tmp = number.index(a[i]) + number.index(b[i]) + f
        else:
            tmp = number.index(a[i]) + f

        if tmp < 36:
            f = 0
        else:
            f = 1
            tmp %= 36

        ret = ret + number[tmp]

    if f == 1:
        ret = ret + "1"

    return ret[::-1].lstrip("0")

ret = ""
for i in range(N):
    s = input()

    t = ""
    for j in s[::-1]:
        idx = number.index(j)
        check[idx] = add(check[idx], number[35 - idx] + t)
        t += "0"

    ret = add(ret, s)

K = int(input())

check.sort(key=lambda x:(len(x), x))
check.reverse()

for i in range(K):
    ret = add(ret, check[i])

print("0" if ret=="" else ret)

"""
2
ZZZY
ZZZZ
ans: 1ZZZY
"""