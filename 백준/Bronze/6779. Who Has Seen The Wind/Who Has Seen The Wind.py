h = int(input())
m = int(input())

t = 1
while t<=m:
    a = -6*(t**4) + h*(t**3) + 2*(t**2) + t
    if a < 0:
        break

    t += 1

if t<=m:
    print(f"The balloon first touches ground at hour: {t}")
else:
    print(f"The balloon does not touch ground in the given time.")