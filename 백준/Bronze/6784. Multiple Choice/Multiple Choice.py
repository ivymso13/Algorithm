N = int(input())

inp = []
for i in range(N):
    t = input()
    inp.append(t)

ret = 0
for i in range(N):
    t = input()
    if t == inp[i]:
        ret += 1

print(ret)