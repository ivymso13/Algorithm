X, Y = map(int, input().split())
N = int(input())

vmin = X/Y
for i in range(N):
    x, y = map(int, input().split())

    vmin = min( vmin, x/y )

print(f'{vmin*1000:.2f}')