n, c = map(int, input().split())

word = ["bedroom", "bathroom", "kitchen", "balcony", "other"]
room = dict()

for w in word:
    room[w] = 0

for _ in range(n):
    sz, name = input().split()
    room[name] += int(sz)

tot = [0, room["bedroom"], 0]
for w in word:
    tot[0] += room[w]

    if w == "balcony":
        tot[2] += room[w]/2
    else:
        tot[2] += room[w]
tot[2] *= c

for val in tot:
    print(val)