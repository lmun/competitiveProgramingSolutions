from functools import reduce

m = 10 ** 7
cri = [0] * m
pri = []
for i in range(2, m):
    if cri[i] == 0:
        cri[i] = i
        pri.append(i)
        for j in range(i * i, m, i):
            cri[j] = i

# def count_divisors(nu):
# 	res = []
# 	no = nu
# 	e = 1
# 	while no>1 and no > cri[no]:
# 		di = cri[no]
# 		e = 0
# 		while no>1 and no%di==0:
# 			no//=di
# 			e+=1
# 		# print(di,no)
# 		res.append((di,e))
# 	if no>1:
# 		res.append((no,1))
# 	return res

mul = lambda x, y: (x * y) % 500500507
prod = lambda x: reduce(mul, x)
di0 = lambda x: prod(y + 1 for x, y in x)
ne = 2
la = 1
# for i in range(2,m):
# 	we = count_divisors(i)
# 	# print(i,di0(we), we)
# 	if di0(we)==ne:
# 		print(i, ne ,we, i/la)
# 		ne*=2
# 		la= i
te = [1] * len(pri)
print("len pri", len(pri))
for i in range(1, 500501):
    # ne = min(t**j for t,j in zip(te,pri))
    ne = pri[0] ** te[0]
    mink = 0
    k = 0
    while te[k] > 1:
        lo, hi = k, len(pri) - 1
        while hi > lo:
            mid = (hi + lo) // 2
            if te[mid] >= te[k]:
                lo = mid + 1
            else:
                hi = mid
        if pri[lo] ** te[lo] < ne:
            ne = pri[lo] ** te[lo]
            mink = lo
        k = lo
    # for k in range(len(te)):
    # 	if pri[k]**te[k] < ne:
    # 		ne = pri[k]**te[k]
    # 		mink = k
    # 	if te[k]==1:
    # 		break
    if mink == len(pri) - 1:
        print("alerta max pri", i)
        print("entrando en loop infinito")
    te[mink] *= 2
print(reduce(lambda x, y: (x * y) % 500500507, (pow(a, (b - 1), 500500507) for a, b in zip(pri, te))))
print(next(i for i in range(len(pri)) if te[i] == 1))
