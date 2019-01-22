for t in range(int(input())):
	n = int(input())
	if n < 3:
		print("IMPOSSIBLE")
		continue
	for j in range(2, n):
		x = (2 * n) - j - (j * j)
		if x < 0:
			print("IMPOSSIBLE")
			break
		if x % (2 * j) == 0:
			wa = x // (2 * j) + 1
			print(n, '=', ' + '.join(map(str, range(wa, wa + j))))
			break
