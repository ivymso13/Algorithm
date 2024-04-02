n = int(input())

for _ in range(n):
    t, c = input().split()
    t = int(t)

    word = ord(c) - 65
    for i in range(1, t+1):
        for j in range(i):
            print(chr(word + 65), end="")
        
        word = (word + 1)%26
        print()
    
    print()