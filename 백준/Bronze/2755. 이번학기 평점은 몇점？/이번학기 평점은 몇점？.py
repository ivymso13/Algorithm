
def calc(inp):
    if inp == "F":
        return 0
    else:
        a, b = inp[0], inp[-1]

        score = (ord("D") - ord(a)) + 1

        if b == "+":
            score += 0.3
        elif b == "-":
            score -= 0.3

        return score

N = int(input())

cnt, tot = 0, 0
for _ in range(N):
    sub, c, score = input().split()

    cnt += int(c)
    tot += int(c)*calc(score)

tot = int(tot/cnt*1000)
if tot%10 < 5:
    print(f"{tot/1000:.2f}")
else:
    print(f"{(tot+1)/1000:.2f}")