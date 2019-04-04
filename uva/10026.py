def compf(a):
	return a[1]/a[0]
for t in range(int(input())):
	input()
	if t:
		print()
	vals = []
	for i in range(int(input())):
		x, s = map(int, input().split())
		vals.append((x, s, i+1))
	vals.sort(key=compf, reverse=True)
	print(" ".join(map(lambda x:str(x[2]), vals)))
