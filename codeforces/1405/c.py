for t in range(int(input())):
	n, k = map(int, input().split())
	wa = ['?']*k
	pala = input().strip()
	res = 'YES'
	for i in range(n):
		if pala[i]!='?':
			if wa[i%k] == '?':
				wa[i%k] = pala[i]
			elif pala[i] != wa[i%k]:
				res = 'NO'
	else:
		a,b = 0,0
		for c in wa:
			if c =='0':
				a+=1
			elif c=='1':
				b+=1
		if 2*a>k or 2*b>k:
			res = 'NO'
	print(res)