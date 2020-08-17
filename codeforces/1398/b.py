for t in range(int(input())):
	s = input().strip()
	re = [0]
	cu = 0
	l = '.'
	for c in s:
		if c==l:
			cu+=1
		else:
			if l=='1':
				re.append(cu)
			l=c
			cu=1
	if l=='1':
		re.append(cu)
	re.sort(reverse=True)
	print(sum(re[::2]))