cnt = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

A = input()
B = input()

num = []
for i in range(len(A)):
    num.append(cnt[ord(A[i])-65])
    num.append(cnt[ord(B[i])-65])

while len(num) > 2:
    tmp = []
    for i in range(len(num)-1):
        tmp.append((num[i] + num[i+1])%10)

    num = tmp

print(num[0], num[1], sep="")