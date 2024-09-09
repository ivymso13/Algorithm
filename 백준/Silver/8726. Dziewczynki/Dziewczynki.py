n, k = map(int, input().split())
inp = list(map(int, input().split()))

g, tmp, ans = 0, 0, n+1
l, r = 0, -1

while r < n:
    if g == k:
        ans = min(ans, tmp)

        if inp[l] == 0:
            g -= 1
        else:
            tmp -= 1

        l += 1
    else:
        r += 1

        if r < n:
            if inp[r] == 0:
                g += 1
            else:
                tmp += 1

print(ans if ans<n+1 else "NIE")