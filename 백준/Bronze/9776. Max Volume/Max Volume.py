N = int(input())
val = []
for i in range(N):
    inp = input().split()

    if inp[0] == "S":
        val.append((4/3)*3.14159*float(inp[1])**3)
    else:
        f = [float(inp[1]), float(inp[2])]

        if inp[0] == "C":
            val.append((1/3)*3.14159*(f[0]**2)*f[1])
        else:
            val.append(3.14159*(f[0]**2)*f[1])

print(f"{max(val):.3f}")