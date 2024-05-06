N = int(input())

ed = 0
bucket = [0]*1010
for i in range(N):
    s, t, b = map(int, input().split())

    bucket[s] += b
    bucket[t+1] -= b

    ed = max(ed, t)

ret = 0
for i in range(1, ed+1):
    bucket[i] += bucket[i-1]

    ret = max(ret, bucket[i])

print(ret)