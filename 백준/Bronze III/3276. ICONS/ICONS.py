N = int(input())

r = c = 1
while r*c < N:
    if r == c:
        r = r+1
    else:
        c = c+1

print(r, c)