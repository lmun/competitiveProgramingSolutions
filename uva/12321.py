while True:
	l, g = map(int, input().split())
	if l == 0 and g == 0:
		break
	sta = []
	for _ in range(g):
		x, r = map(int, input().split())
		sta.append((x-r, x+r))
	sta.sort()
	res = 1
	i = 0
	nmaxi = -1
	mini = 0
	actmaxi = 0
	while i < len(sta) and nmaxi < l:
		x, y = sta[i]
		if x <= actmaxi:
			nmaxi = max(nmaxi, y)
		else:
			if nmaxi > mini:
				mini = nmaxi
				actmaxi = nmaxi
				res += 1
				continue
			else:
				print(-1)
				break
		i += 1
	else:
		if nmaxi >= l:
			print(g-res)
		else:
			print(-1)
