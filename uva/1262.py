from functools import reduce
for t in range(int(input())):
	k = int(input())
	pri = [input().strip() for _ in range(6)]
	seg = [input().strip() for _ in range(6)]
	pris = [set() for _ in range(5)]
	segs = [set() for _ in range(5)]
	for p in pri:
		for i in range(5):
			pris[i].add(p[i])
	for p in seg:
		for i in range(5):
			segs[i].add(p[i])
	res = [list(sorted(a&b)) for a,b in zip(pris, segs)]
	res.reverse()
	posis = reduce(int.__mul__, (len(r) for r in res))
	if k > posis:
		print("NO")
	else:
		k -= 1
		resp = []
		for l in res:
			resp.append(str(l[k%len(l)]))
			k //= len(l)
		print(''.join(reversed(resp)))
