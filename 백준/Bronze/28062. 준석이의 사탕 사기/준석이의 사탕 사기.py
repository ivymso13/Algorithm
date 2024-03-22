N = int(input())
inp = list(map(int, input().split()))

odd = 1010
tot = sum(inp)
for val in inp:
    if val%2 == 1:
        odd = min(odd, val)

if tot%2 == 0:
    print(tot)
else:
    print(tot - odd)