N = int(input())
inp = list(input())

A = inp.count("A")
B = inp.count("B")

print("A" if A>B else "B" if A<B else "Tie")