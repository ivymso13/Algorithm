PI = 3.141592653589793
K = int(input())
for i in range(K):
    b, w = map(float, input().split())

    balloon = 0
    for j in range(int(b)):
        r = float(input())
        balloon += (r**3)*4*PI/3

    print(f"Data Set {i+1}:")
    if balloon/1000 >= w:
        print("Yes")
    else:
        print("No")
    print()