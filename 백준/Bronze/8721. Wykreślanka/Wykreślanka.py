N = int(input())
inp = map(int, input().split())

idx = 1
for num in inp:
    if num == idx:
        idx += 1

print(N-(idx-1))