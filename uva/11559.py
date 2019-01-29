try:
	while True:
		n, b, h, w = map(int,input().split())
		res = 2 * b
		for i in range(h):
			c = int(input())
			if max(map(int, input().split())) >= n:
				res = min(res, n*c)
		if res <= b:
			print(res)
		else:
			print("stay home")
except Exception as e:
	pass
else:
	pass
finally:
	pass