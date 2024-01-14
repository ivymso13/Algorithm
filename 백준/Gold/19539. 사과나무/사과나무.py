N = int(input())
inp = list(map(int, input().split()))

tot = cnt = 0
for val in inp:
    tot += val
    cnt += val//2

if tot%3 != 0:
    print("NO")
else:
    if cnt < tot//3:
        print("NO")
    else:
        print("YES")
"""        
6
1 1 1 3 3 3
ans: NO

6
1 1 1 3 3 6
ans: YES
"""