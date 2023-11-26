N = int(input())
X, Y, R = map(int, input().split())

A = B = 0
for _ in range(N):
    t = int(input())

    if X-R<t<X+R:
        A += 1
    elif X-R==t or X+R==t:
        B += 1

print(A, B)