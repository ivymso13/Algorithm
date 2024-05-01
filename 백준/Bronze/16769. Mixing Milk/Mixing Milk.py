c, m = [], []
for i in range(3):
    a, b = map(int, input().split())

    c.append(a)
    m.append(b)

for i in range(100):
    cur = i%3
    nxt = (cur+1)%3
    tot = m[cur] + m[nxt]
    
    m[nxt] = min(c[nxt], tot)
    m[cur] = max(0, tot-c[nxt])

for i in range(3):
    print(m[i])