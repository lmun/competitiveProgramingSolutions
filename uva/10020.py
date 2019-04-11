for t in range(int(input())):
	input()
	m = int(input())
	seg = []
	while True:
		x, y = map(int, input().split())
		if x == 0 and y == 0:
			break
		seg.append((x, y))
	seg.sort()
	mini = 0
	mii = 0
	mai = -1
	res = 1
	maii = 0
	resp = []
	while mii < len(seg):
		if seg[mii][0] <= mini:
			if seg[mii][1] > mai:
				mai = seg[mii][1]
				maii = mii
		else:
			if mai >= m:
				break
			if mai > mini:
				mini = mai
				res += 1
				resp.append(seg[maii])
				continue
			else:
				break
		mii += 1
	resp.append(seg[maii])
	if mai >= m:
		print(res)
		for x, y in resp:
			print(x, y)
	else:
		print(0)
	print()
