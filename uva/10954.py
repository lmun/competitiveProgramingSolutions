from heapq import heappop, heappush
while True:
	n = int(input())
	h = []
	if n == 0:
		break
	for x in input().split():
		heappush(h, int(x))
	res = 0
	while True:
		a = heappop(h)
		if h:
			b = heappop(h)
			res += a + b
			heappush(h, a + b)
		else:
			print(res)
			break