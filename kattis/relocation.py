n, q = map(int, input().split())
pos = [int(x) for x in input().split()]
for t in range(q):
	a, b, c = map(int, input().split())
	if a == 1:
		pos[b-1] = c
	else:
		print(abs(pos[b-1]-pos[c-1]))
