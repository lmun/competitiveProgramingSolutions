from heapq import heappop, heappush
h = []
while True:
	w = input().strip()
	if w == '#':
		break
	b, c = map(int, w.split()[1:])
	heappush(h, (c,(b, c)))
for i in range(int(input())):
	top = heappop(h)
	print(top[1][0])
	heappush(h, (top[0] + top[1][1], top[1]))
