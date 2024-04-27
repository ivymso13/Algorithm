while True:
 N, D = map(int, input().split())
 if N == D == 0:
  break

 inp = [0]*N
 for i in range(D):
  tmp = list(map(int, input().split()))
  for j in range(N):
   inp[j] += tmp[j]

 f = 0
 for j in range(N):
  if inp[j] == D:
   f = 1

 print("yes" if f else "no")