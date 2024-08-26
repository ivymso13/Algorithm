T = int(input())
for i in range(1, T+1):
    a, b, c = map(int, input().split())
    a, b, c = min(a, b, c), (a+b+c)-min(a,b,c)-max(a,b,c), max(a,b,c)

    print(f"Scenario #{i}:")
    if a**2 + b**2 == c**2:
        print(f"yes\n")
    else:
        print(f"no\n")