for _ in range(int(input())):
	a = input().strip()
	if a == 'P=NP':
		print('skipped')
	else:
		print(sum(map(int,a.split('+'))))
