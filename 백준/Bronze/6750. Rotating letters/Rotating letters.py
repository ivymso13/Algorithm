check = ['I', 'O', 'S', 'H', 'Z', 'X', 'N']
inp = input()

f = 1
for c in inp:
    if c not in check:
        f = 0

print("YES" if f == 1 else "NO")