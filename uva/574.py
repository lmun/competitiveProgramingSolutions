from itertools import product

while True:
	try:
		li = [int(x) for x in input().split()]
		t = li[0]
		n = li[1]
		nu = li[2:]
		if t == 0 and n == 0:
			break
		lk = []
		lv = []
		for j in range(n):
			if lk and nu[j] == lk[-1]:
				lv[-1] += 1
			else:
				lk.append(nu[j])
				lv.append(1)
		hay = False
		print("Sums of {}:".format(t))
		for aa in product(*(reversed(range(x+1)) for x in lv)):
			if sum(map(lambda x:x[0]*x[1],zip(aa,lk))) == t:
				print('+'.join(filter(None,map(lambda x:'+'.join([str(x[1])]*x[0]), zip(aa, lk)))))
				hay = True
		if not hay:
			print("NONE")

	except Exception as e:
		print(e)
		break
