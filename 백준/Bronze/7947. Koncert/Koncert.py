T = int(input())
for i in range(T):
    rgb = [0, 0, 0]
    for j in range(10):
        inp = list(map(int, input().split()))

        for k in range(3):
            rgb[k] += inp[k]

    for j in range(3):
        rgb[j] = (rgb[j]+5)//10

    print(rgb[0], rgb[1], rgb[2])