N, X = input().split()
a, b = map(int, X.split('.'))

N = int(N)
X = a*100 + b

key = ["A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"]
value = [450, 400, 350, 300, 250, 200, 150, 100, 0]
check = dict()
for k, v in zip(key, value):
    check[k] = v

tot, score = 0, 0
for i in range(N-1):
    t, s = input().split()
    t = int(t)

    tot += t
    score += (check[s]*t)

t = int(input())
tot += t

ret = "impossible"
for i in range(8, -1, -1):
    if (score+(value[i]*t))//tot > X:
        ret = key[i]
        break

print(ret)