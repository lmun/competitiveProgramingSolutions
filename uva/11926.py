maxi = 10**6
while True:
	n, m = map(int, input().split())
#	print(n, m)
	if n == 0 and m == 0:
		break
	inter = [0]*maxi
	posi = True
	for _ in range(n):
		a, b = map(int, input().split())
		for o in range(a,b):
			if inter[o] == 1:
				posi = False
			inter[o] = 1
	for j in range(m):
		a, b, c = map(int, input().split())
		x = 0
		while posi:
			if a + c * x >= maxi:
				break
			for o in range(a + c * x, min(b + c * x,maxi-1)):
				if inter[o] == 1:
					posi = False
				inter[o] = 1
			x += 1
	if not posi:
		print("CONFLICT")
	else:
		print("NO CONFLICT")