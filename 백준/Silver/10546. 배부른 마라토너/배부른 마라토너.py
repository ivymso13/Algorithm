N = int(input())

inp = []
for _ in range(N):
    t = input()
    inp.append(t)

fin = []
for _ in range(N-1):
    t = input()
    fin.append(t)

inp.sort()
fin.sort()

for i in range(N):
    if i == N-1 or inp[i] != fin[i]:
        ret = inp[i]
        break

print(ret)