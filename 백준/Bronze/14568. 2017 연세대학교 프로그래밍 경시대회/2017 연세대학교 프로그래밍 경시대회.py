N = int(input())

cnt = 0
for a in range(1, N):
    for b in range(a+2, N):
        c = N-(a+b)
        if c>0 and c%2 == 0:
            cnt += 1
            
print(cnt)