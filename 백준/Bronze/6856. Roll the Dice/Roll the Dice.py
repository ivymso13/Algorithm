N = int(input())
M = int(input())

ret = 0
for i in range(1, min(11, N+1)):
    if 0<10-i<=M:
        ret += 1

if ret == 1:
    print(f"There is {ret} way to get the sum 10.")
else:
    print(f"There are {ret} ways to get the sum 10.")