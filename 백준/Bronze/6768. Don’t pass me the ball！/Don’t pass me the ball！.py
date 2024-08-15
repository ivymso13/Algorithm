N = int(input())

if N < 4:
    print(0)
else:
    print((N-1)*(N-2)*(N-3)//6)