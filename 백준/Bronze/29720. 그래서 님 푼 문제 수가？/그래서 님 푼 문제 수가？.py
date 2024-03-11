N, M, K = map(int, input().split())

vmax = N - (M*(K-1)+1)
vmin = max(0, N - (M*K))

print(vmin, vmax)