T = int(input())
for _ in range(T):
  n = list(input())
  l = len(n)

  ret = "Do-it"
  if n[l//2-1] != n[l//2]:
    ret += "-Not"

  print(ret)