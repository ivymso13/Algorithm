la = "Latitude "
for i in range(3):
    t = input()
    if t[-1] == " ":
        t = t[:-1]
    la += str(len(t)) + ":"

lo = "Longitude "
for i in range(3):
    t = input()
    if t[-1] == " ":
        t = t[:-1]
    lo += str(len(t)) + ":"

la = la[:-1]
lo = lo[:-1]

print(la)
print(lo)