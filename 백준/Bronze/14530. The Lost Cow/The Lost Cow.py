x, y = map(int, input().split())

d, f, ret = 1, 1, 0
cur, ed = x, x+1
while cur != y:
    if cur == ed:
        d *= 2
        f *= -1
        ed = x + d*f

    cur += f
    ret += 1

print(ret)