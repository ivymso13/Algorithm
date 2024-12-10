N = int(input())
inp = list(map(int, input().split()))

cnt = [0, 0]
for val in inp:
    cnt[val%2] += 1

ans = min(cnt)*2
cnt = [cnt[0]-min(cnt), cnt[1]-min(cnt)]

if cnt[0] > cnt[1]:
    ans += 1
else:
    if cnt[1]%3 == 1:
        cnt[1] -= 2

    if cnt[1]%3 == 0:
        ans += cnt[1]//3*2
    else:
        ans += (cnt[1]//3*2 + 1)

print(ans)