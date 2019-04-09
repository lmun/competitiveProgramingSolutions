from math import sqrt
try:
	t = 0
	while True:
		t += 1
		n, l, w = map(int, input().split())
		seg = []
		for _ in range(n):
			p, r = map(int, input().split())
			if 2*r>w:
				d = sqrt(r*r - w*w/4)
				seg.append((p-d, p+d))
		seg.sort()
		i = 0
		mini = 0
		mai = 0
		res = 1
		while i < len(seg):
			tx, ty = seg[i]
			if tx <= mini:
				if ty > seg[mai][1]:
					mai = i
				i += 1
			else:
				if seg[mai][1] > mini:
					if seg[mai][1] >= l:
						break
					res += 1
					mini = seg[mai][1]
					# print(seg[mai])
				else:
					res = -1
					break
		if len(seg) and seg[0][0] <= 0 and seg[mai][1] >= l:
			print(res)
		else:
			print(-1)
except Exception as e:
	pass
