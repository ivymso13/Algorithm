T = int(input())
for i in range(T):
    N, D, A, B, F = map(float, input().split())

    print(f"{N} {(D*F)/(A+B):.3f}")

"""
5
1 250 10 15 20
2 10.7 3.5 4.7 5.5
3 523.7 15.3 20.7 33.3
4 1000 30 30 50
5 500 15 15 25
"""