N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]
check = [[0]*(N+1) for _ in range(N+1)]
for _ in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    graph[B].append(A)

    check[A][B] = check[B][A] = 1

ret = INF = 4000*4000*4000
for i in range(1, N+1):
    cnt = len(graph[i])
    if cnt < 2:
        continue

    for ii in range(cnt):
        for jj in range(ii+1, cnt):
            if check[graph[i][ii]][graph[i][jj]] == 0:
                continue

            cur = cnt + len(graph[graph[i][ii]]) + len(graph[graph[i][jj]]) - (4 + check[graph[i][ii]][graph[i][jj]]*2)
            ret = min(ret, cur)

print(-1 if ret == INF else ret)