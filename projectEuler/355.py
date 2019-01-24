m = 10**6+1
cri = [0]*m
nums = [0]*m
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        for j in range(i*i, m, i):
            cri[j] = i

s = set()
r = 0
for i in reversed(range(1, int(input()))):
    if cri[i] not in s:
        s.add(cri[i])
        r += i
print(r)
