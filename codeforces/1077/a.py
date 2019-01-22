for i in range(int(input())):
	a, b, k = map(int, input().split())
	r = (a-b)*(k//2)
	if k % 2 == 1:
		r += a
	print(r)
