N, M = map(int, input().split())

x = (N-1)%(M+1)

print("Can't win" if x == 0 else "Can win")