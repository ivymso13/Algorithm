fbi = []
for p in range(5):
    id = input()
    for i in range(len(id)-2):
        cur = id[i:i+3]
        if cur == "FBI":
            fbi.append(p+1)
            break

if len(fbi) == 0:
    print('HE GOT AWAY!')
else:
    for idx in fbi:
        print(idx, end=" ")
