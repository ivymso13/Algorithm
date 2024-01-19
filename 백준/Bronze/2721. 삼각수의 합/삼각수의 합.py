T = int(input())

ret = [0]
for i in range(1, 301):
    ret.append(ret[-1] + i*(i+1)*(i+2)//2)

for _ in range(T):
    n = int(input())
    print(ret[n])