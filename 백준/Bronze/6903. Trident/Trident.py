a = int(input())
b = int(input())
c = int(input())

for i in range(a+c+1):
    if i < a:
        print("*" + " "*b + "*" + " "*b + "*")
    elif i == a:
        print("*"*(2*b+3))
    else:
        print(" "*(b+1) + "*")