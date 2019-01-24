for t in range(1,10000):
	i=int(input())
	if i==0:
		break
	ws=list()
	for _ in range(i):
		ws.append(input())
	print("SET", t)
	for a in range(2*(i//2)-1,0,-2):
		print(ws[a])
	for a in reversed(range(1,i,2)):
		print(ws[a])