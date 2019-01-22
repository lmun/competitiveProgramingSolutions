def isdist(li, ind):
	return li[ind] == li[ind+2] and li[ind] == 1 and li[ind+1] == 0


n = int(input())
lals = list(map(int, input().split()))
rals = list(reversed(lals))
rl = 0
tl = 0
for i in range(n-2):
	if isdist(lals, i):
		lals[i+2] = 0
		tl += 1
	if rals[i]==rals[i+2] and rals[i] == 1 and rals[i+1]==0:
		rals[i+2] = 0
		rl += 1
print(min(rl, tl))