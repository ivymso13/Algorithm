N = int(input())
a = list(map(int, input().split()))

f = False
if N >= 2:
    d = a[1] - a[0]
    for i in range(2, N):
        if a[i] - a[i-1] != d:
            f = True
            break

if f:
    print("NO")
else:
    print("YES")
    for i in range(N):
        print(a[i], end=" ")
    print()
    for i in range(N):
        print(0, end=" ")
