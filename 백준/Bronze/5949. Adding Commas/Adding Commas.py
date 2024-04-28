n = list(input())
n.reverse()

ret = ""
for i in range(len(n)):
    if i>0 and i%3 == 0:
        ret = str(n[i]) + "," + ret
    else:
        ret = str(n[i]) + ret

print(ret)