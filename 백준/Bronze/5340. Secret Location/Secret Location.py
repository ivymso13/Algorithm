la = "Latitude "
for i in range(3):
    t = input().strip()
    la += str(len(t)) + ":"

lo = "Longitude "
for i in range(3):
    t = input().strip()
    lo += str(len(t)) + ":"

la = la[:-1]
lo = lo[:-1]

print(la)
print(lo)