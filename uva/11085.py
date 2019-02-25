from itertools import permutations

def posi(p):
	dia1 = [0]*15
	dia2 = [0]*15
	for i in range(8):
		a = p[i] + i
		b = p[i] - i + 7
		if dia1[a] > 0 or dia2[b] > 0:
			return False
		dia1[a] += 1
		dia2[b] += 1
	return True

posis = [p for p in permutations(range(8)) if posi(p)]
t = 1
while True:
	try:
		q = [int(x) - 1 for x in input().split()]
		print("Case {}: {}".format(t, min(sum(0 if x==y else 1 for x,y in zip(q, p)) for p in posis)))
		t += 1
	except Exception as e:
		#print(e)
		break
