def convert(t):
    return int(t[::-1])


N = int(input())
for _ in range(N):
    a, b = map(convert, input().split())
    print(int(str(a + b)[::-1]))