from itertools import combinations
pri = False
while True:
	try:
		x = list(input().split())
		if x[0] == '0':
			break
		if pri:
			print()
		pri = True
		for p in combinations(x[1:], 6):
			print(' '.join(p))
	except Exception as e:
		break
