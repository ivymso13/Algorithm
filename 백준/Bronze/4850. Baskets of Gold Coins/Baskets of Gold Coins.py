while True:
    try:
        N, w, d, tot = map(int, input().split())

        ret = ( w*N*(N-1)//2 - tot )//d
        
        if ret == 0:
            print(N)
        else:
            print(ret)
    except:
        break