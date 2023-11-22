N = int(input())
inp = input()

f = 1
len = N//2
for i in range(len):
    if inp[i] != inp[i+len]:
        f = 0
        break

print("Yes" if f == 1 else "No")