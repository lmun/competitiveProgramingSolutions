for t in range(int(input())):
	a,b = map(int, input().split())
	d = abs(a-b)
	if d == 0:
		print(0)
	else:
		print((d-1)//10+1)