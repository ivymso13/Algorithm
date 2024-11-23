N = int(input())

val = [2,2,-1]
if N%3 == 2:
    num = [1, 2]
    idx = 1
else:
    num = [1, 3, 2]
    idx = 0

while True:
    t = num[-1] + val[idx]
    if t <= N:
        num.append(t)
        idx = (idx+1)%3
    else:
        num.append(1)
        break

print(N)
for val in num:
    print(val, end=" ")