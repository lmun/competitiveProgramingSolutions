def pred(a, b):
	val = 0
	res = 0
	for i in range(1, a+1):
		if a <= i*b:
			break
		el = i*(a-i*b)
		#print(i, el)
		if el == val:
			return 0
		if el > val:
			val = el
			res = i
	return res

while True:
	try:
		x,y  = map(int, input().split())
		if x == y and y == 0:
			break
		print(pred(x, y))
	except Exception as e:
		break