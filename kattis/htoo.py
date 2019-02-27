from collections import defaultdict

def stodict(x):
	di = defaultdict(int)
	t = 0
	while t < len(x):
		c = x[t]
		ini = t
		t += 1
		while t < len(x) and x[t].isdigit():
			t += 1
		di[x[ini]] += int(x[ini+1:t] or '1')
	return di

x, y = input().split()
di = stodict(x)
du = stodict(input().strip())
res = 10**20
for r, v in du.items():
	res = min(res, (di[r] * int(y)) // v)
print(res)
