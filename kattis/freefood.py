se = set()
for t in range(int(input())):
    a, b = map(int, input().split())
    se |= set(range(a, b+1))
print(len(se))
