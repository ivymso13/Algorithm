ans = [0]
for i in range(1, 80001):
    if i%3 == 0 or i%7 == 0:
        ans.append(ans[i-1] + i)
    else:
        ans.append(ans[i-1])

T = int(input())
inp = list(map(int, input().split()))

for val in inp:
    print(ans[val])