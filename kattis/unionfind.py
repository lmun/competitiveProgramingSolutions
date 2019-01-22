def getrepe(n):
	if repes[n] == n:
		return n
	else:
		repes[n] = getrepe(repes[n])
		return repes[n]


x, q = map(int, input().split())
repes = [i for i in range(x)]
tama = [1] * x
for _ in range(q):
	p, a, b = input().split()
	na = int(a)
	nb = int(b)
	rena = getrepe(na)
	renb = getrepe(nb)
	if p == '?':
		print('yes' if rena == renb else 'no')
	else:
		if tama[rena] > tama[renb]:
			repes[renb] = rena
		else:
			repes[rena] = renb
