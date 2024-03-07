N = int(input())

rule = []
for _ in range(N):
    rule.append(input())

M = int(input())
for _ in range(M):
    idx = int(input())

    if 1<=idx<=N:
        print(f"Rule {idx}: {rule[idx-1]}")
    else:
        print(f"Rule {idx}: No such rule")