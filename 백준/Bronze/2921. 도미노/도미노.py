N = int(input())

ret = 0
for i in range(N+1):
    ret += i*(i+1) + i*(i+1)//2

print(ret)