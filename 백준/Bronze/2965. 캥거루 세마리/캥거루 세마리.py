a, b, c = map(int, input().split())

dist = max(b-a, c-b)-1

print(dist)