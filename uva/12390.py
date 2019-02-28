# tle on uva, ac on kattis
while True:
	try:
		x,y = map(int, input().split())
		if x == -1  and y == -1:
			break
		vals = [int(input()) for _ in range(x)]
		l = 1
		h = 1
		while sum((v-1)//h + 1 for v in vals) > y:
			h *= 2
		# print(sum( ((v-1)//h) + 1 for v in vals))
		while h > l:
			mid = (h+l)//2
			# print(l, h, sum( ((v-1)//mid) + 1 for v in vals))
			if sum((v-1)//mid + 1 for v in vals) > y:
				l = mid + 1
			else:
				h = mid
		print(l)
		input()
	except Exception as e:
		break
