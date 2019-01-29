while True:
	try:
		lar = int(input())
		ins = list(input().split())
		x, y, z = 1, 0, 0
		for i in ins:
			# print(i)
			if i == "+z":
				x, y, z = -z, y, x
			elif i == "-z":
				x, y, z = z, y, -x
			elif i == "+y":
				x, y, z = -y, x, z
			elif i == "-y":
				x, y, z = y, -x, z
		if x != 0:
			print("+x" if x == 1 else "-x")
		if y != 0:
			print("+y" if y == 1 else "-y")
		if z != 0:
			print("+z" if z == 1 else "-z")
	except Exception as e:
		break
	else:
		pass
	finally:
		pass