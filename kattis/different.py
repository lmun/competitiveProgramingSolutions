while True:
	try:
		x, y = map(int, input().split())
		print(abs(x-y))
	except Exception as e:
		break
