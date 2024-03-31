N = int(input())

win = [0, 0]
for _ in range(N):
    a, b = map(int, input().split())

    if a > b:
        win[0] += 1
    elif a < b:
        win[1] += 1

print(win[0], win[1])