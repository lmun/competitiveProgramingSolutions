for t in range(int(input())):
	n,x,y = map(int, input().split())
	di = y - x
	midi = y-x
	for i in range(2,n):
		if di%i==0:
			midi = di//i
	res = []
	for i in range(n):
		if y > i*midi:
			res.append(y-i*midi)
		else:
			break
	u = 1
	while len(res)<n:
		res.append(y+u*midi)
		u+=1
	print(' '.join(map(str,res)))