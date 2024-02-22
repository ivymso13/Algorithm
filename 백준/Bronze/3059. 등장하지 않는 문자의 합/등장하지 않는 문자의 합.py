T = int(input())

for _ in range(T):
    inp = input()
    check = [1]*100

    for val in inp:
        check[ord(val)] = 0

    ret = 0
    for i in range(ord('A'), ord('Z')+1):
        ret += i*check[i]

    print(ret)