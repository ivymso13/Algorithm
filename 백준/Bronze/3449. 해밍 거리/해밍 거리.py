T = int(input())
for i in range(T):
    a = input()
    b = input()

    cnt = 0
    for j in range(len(a)):
        if a[j] != b[j]:
            cnt += 1

    print(f"Hamming distance is {cnt}.")