for t in range(int(input())):
	n = int(input())
	aa = [int(x) for x in input().split()]
	bb = [int(x) for x in input().split()]
	ma = min(aa)
	mb = min(bb)
	na = [a-ma for a in aa]
	nb = [b-mb for b in bb]
	res = 0
	for i in range(n):
		res += na[i] if na[i] > nb[i] else nb[i]
	print(res)
