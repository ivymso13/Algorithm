small = []

for i in range(9):
    small.append(int(input()))
    
small.sort()

for i in range(0, 9):
    for j in range(0, 9):
        if i != j:
            a = 0
            for k in range(0, 9):
                if k!=i and k!=j:
                    a = a + small[k]
            
            if a == 100:
                break
    if a == 100:
        break
    

for k in range(9):
    if k!=i and k!=j:
        print(f"{small[k]}")
                









