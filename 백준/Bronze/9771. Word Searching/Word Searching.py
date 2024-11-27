wd = input()
cnt = 0
while True:
    try:
        inp = input().split()
        for val in inp:
            if wd in val:
                cnt += 1

    except:
        break

print(cnt)