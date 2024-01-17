N = int(input())

r1 = list(map(abs, map(int, input().split())))
r2 = list(map(abs, map(int, input().split())))

print(sum(r1) + sum(r2))