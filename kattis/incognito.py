for i in range(int(input())):
	ma = {}
	for j in range(int(input())):
		a, b = input().split()
		ma[b] = ma.get(b, 1) + 1
	res = 1
	for ka in ma:
		res *= ma[ka]
	print(res-1)
