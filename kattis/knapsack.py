try:
	while True:
		x, y = input().split()
		x = float(x)
		x = int(x)
		y = int(y)
		# print(x, y)
		k = [[0]*(int(x+10)) for i in range(y+10)]
		j = [[[] for o in range(x + 10)] for _ in range(y+10)]
		for i in range(y):
			v, w = map(int, input().split())
			for t in range(x+1):
				#print(1)
				if w > t:
					k[i+1][t] = k[i][t]
					j[i+1][t] = j[i][t]
				else:
					a = v + k[i][t-w]
					b = k[i][t]
					if a > b:
						#print(a, b)
						k[i+1][t] = a
						j[i+1][t] = j[i][t-w] + [i]
						#print(j[i+1][t], j[i][t-w])
					else:
						k[i+1][t] = k[i][t]
						j[i+1][t] = j[i][t]
		#print(k[y][x])
		print(len(j[y][x]))
		print(' '.join(map(str, j[y][x])))
			
except Exception as e:
	pass
