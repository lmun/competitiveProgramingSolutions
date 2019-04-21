for t in range(int(input())):
	l = int(input())
	field = input().strip()
	lf = len(field)
	i = 0
	res = 0
	while i < lf:
		if field[i] == '.':
			i += 2
			res += 1
		i += 1
	print("Case {}: {}".format(t+1, res))
