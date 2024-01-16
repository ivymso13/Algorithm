A = list(input())
B = list(input())

ret = ""
for i in range(len(A)):
    ret += A[i] + B[i]

while len(ret) > 2:
    tmp = ""
    for i in range(1, len(ret)):
        tmp += str((int(ret[i]) + int(ret[i-1]))%10)

    ret = tmp

print(ret[0] + ret[1])