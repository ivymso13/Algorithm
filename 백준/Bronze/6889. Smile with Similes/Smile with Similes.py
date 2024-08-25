n = int(input())
m = int(input())

A, B = [], []
for i in range(n):
    t = input()
    A.append(t)
for j in range(m):
    t = input()
    B.append(t)

for a in A:
    for b in B:
        print(f"{a} as {b}")