while True:
	try:
		n = int(input())
		books = [int(x) for x in input().split()]
		books.sort()
		m = int(input())
		#print(books)
		x = ini = 0
		y = fin = n-1
		while fin > ini:
			if books[fin] + books[ini] > m:
				fin -= 1
			elif books[fin] + books[ini] < m:
				ini += 1
			else:
				x, y = books[ini], books[fin]
				fin -= 1
				ini += 1
		print("Peter should buy books whose prices are {} and {}.".format(x,y))
		print()
		input()
	except Exception as e:
		#print(e)
		break
