M, H = map(int, input().split())
N = int(input())

ret = 0
for i in range(N):
    a, b = map(int, input().split())
    ret += max(a*M, b*H)

print(ret)