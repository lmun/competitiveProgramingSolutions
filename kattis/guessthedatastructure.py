# Same as uva 11995
from heapq import heappop, heappush
while True:
	try:
		n = int(input())
		h = []
		s = []
		q = []
		posi = [1, 1, 1]
		for _ in range(n):
			a, b = map(int, input().split())
			if a == 1:
				heappush(h, -b)
				s.append(b)
				q.append(b)
			else:
				if len(s) == 0:
					posi = [0, 0, 0]
					continue
				if posi[0] == 1 and -b != heappop(h):
					posi[0] = 0
				if posi[1] == 1 and b != s.pop():
					posi[1] = 0
				if posi[2] == 1 and b != q.pop(0):
					posi[2] = 0
		if sum(posi) > 1:
			print("not sure")
		elif sum(posi) == 0:
			print("impossible")
		elif posi[0] == 1:
			print("priority queue")
		elif posi[1] == 1:
			print("stack")
		elif posi[2] == 1:
			print("queue")
	except Exception as e:
		break
