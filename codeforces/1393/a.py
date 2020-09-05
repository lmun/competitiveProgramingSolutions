for x in range(3, 10):
	mat = [[0]*x for _ in range(x)]
	dirs = [(0,1),(-1,0),(1,0),(0,-1)]
	co = 0
	for i in range(x):
		if i%2==1:
			mat[0][i] = 2
			mat[i][0] = 2
		if (x-1+i)%2==0:
			mat[x-1][i] = 2
			mat[i][x-1] = 2
	cambio = True
	while cambio:
		cambio=False
		# for t in range(x):
		# 	print(''.join(map(str, mat[t])))
		oldma = [[x for x in mat[i]] for i in range(x)]
		for i in range(x):
			for j in range(x):
				if mat[i][j]==0:
					for a, b in dirs:
						aa,bb = a+i, j+b
						if 0<=aa<x and 0<=bb<x and oldma[aa][bb]>0:
							mat[i][j] = (oldma[aa][bb]%2) + 1
							cambio = True
		co += 1
		print()
	print(x,co)
