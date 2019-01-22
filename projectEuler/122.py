mama = 0

def nono(li, ma, nu):
	global mama
	# print(ma, nu, li)
	li.append(ma)
	if ma > 201:
		return
	if wa[ma] > nu:
		# print(ma, wa[ma], nu)
		wa[ma] = nu
	sig = ''.join(map(str, li))
	if sig in camis[ma]:
		return
	if wa[ma] == nu:
		camis[ma].add(sig)
		if len(camis[ma]) > mama:
			mama = len(camis[ma])
			print(mama, ma, li)
		for n in reversed(li):
			"""if wa[ma+n] > nu +1:
				print('a')
			else:
				print('b')
			"""
			nono(list(li), ma + n, nu + 1)

wa = [1000000] * 250
camis = [set() for _ in range(250)]
li = [1]
nono([1], 2, 1)
print(wa[:210])
print(sum(wa[:210]))