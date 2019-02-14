from itertools import product
from functools import reduce

MUL = int.__mul__
m = 11000
cri = [0]*m
pri = []
for i in range(2, m):
	if cri[i] == 0:
		cri[i] = i
		pri.append(i)
		for j in range(i * i, m, i):
			cri[j] = i


def nuso(n):
	resp = 1
	while n > 1:
		divi = cri[n]
		co = 0
		while n > 1 and n % divi == 0:
			n //= divi
			co += 1
		resp *= (2*co + 1)
	return resp // 2 + 1


def divis(n):
	rr = {}
	while n > 1:
		divi = cri[n]
		co = 0
		while n > 1 and n % divi == 0:
			n //= divi
			co += 1
		rr[divi] = 2 * co
	return rr


while True:
	try:
		n = int(input())
		print(nuso(n))
		#print(divis(n))
		n2 = n*n
		pf = divis(n)
		pfactors, occurrences = pf.keys(), pf.values()
		multiplicities = product(*(range(oc + 1) for oc in occurrences))
		#print(multiplicities)
		divs = [reduce(MUL, (pf**m for pf, m in zip(pfactors, multis)), 1)
            for multis in multiplicities]
		divs.sort()
		for xx in divs:
			if xx > n:
				break
			print("1/{} = 1/{} + 1/{}".format(n, n2//xx+n, xx+n))
	except Exception as e:
		#print(e)
		break
