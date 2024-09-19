N, M, L = map(int, input().split())

inp = []
for i in range(M):
    inp.append(int(input()))

for i in range(N):
    q = int(input())

    l, r = 0, L
    ans = 0
    while l<=r:
        mid = (l+r)//2

        mCake, cut, bef = L, 0, 0
        for j in range(M):
            if inp[j]-bef >= mid and cut < q:
                mCake = min(mCake, inp[j]-bef)
                bef = inp[j]
                cut += 1

        mCake = min(mCake, L-bef)

        if cut < q:
            r = mid-1
        else:
            ans = max(ans, mCake)
            if mCake < mid:
                r = mid-1
            else:
                l = mid+1

    print(ans)
