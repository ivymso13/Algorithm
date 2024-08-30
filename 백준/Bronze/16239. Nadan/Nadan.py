N = int(input())
T = int(input())

tot = 0
for i in range(1, T):
    tot += i
    print(i)
print(N-tot)