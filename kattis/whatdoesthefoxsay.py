for _ in range(int(input())):
	palas = list(input().split())
	words = set(palas)
	cono = set()
	while True:
		say = list(input().split())
		if len(say) > 3:
			break
		cono.add(say[2])
	fox = words - cono
	for word in palas:
		if word in fox:
			print(word, end=' ')
	print()