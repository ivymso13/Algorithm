T = int(input())

score = [[1,2,3,3,4,10], [1,2,2,2,3,5,10]]

for idx in range(T):
    inp = []
    for i in range(2):
        t = list(map(int, input().split()))
        inp.append(t)

    tot = [0, 0]
    for i in range(2):
        for j in range(len(inp[i])):
            tot[i] += score[i][j]*inp[i][j]

    print(f"Battle {idx+1}: ", end="")
    if tot[0] > tot[1]:
        print(f"Good triumphs over Evil")
    elif tot[0] < tot[1]:
        print(f"Evil eradicates all trace of Good")
    else:
        print(f"No victor on this battle field")

