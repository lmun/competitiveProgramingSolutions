while True:
	n, d, r = map(int, input().split())
	if n == 0 and d == 0 and r == r:
		break
	mo = [int(x) for x in input().split()]
	af = [int(x) for x in input().split()]
	mo.sort()
	af.sort(reverse=True)
	cos = [x+y-d for x, y in zip(mo,af)]
	res = r*sum(c for c in cos if c >= 0)
	print(res)
