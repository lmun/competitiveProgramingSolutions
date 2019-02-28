from functools import reduce
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def todosIugales(x):
	return all(x[0] == i for i in x)

def multigram(word):
	if len(word) == 1:
		return word
	mapa = {}
	for c in word:
		mapa[c] = mapa.get(c, 0) + 1
	# print(max(mapa.values()))
	copi = reduce(gcd, mapa.values())
	#print(mapa)
	sepa = [word[g:g + len(word)//copi] for g in range(0, len(word), len(word)//copi)]
	sepa2 = list(map(lambda x:''.join(sorted(x)), sepa))
	# print(todosIugales(sepa2))
	# print(sepa2)
	if copi == 1:
		return word
	elif copi == len(word):
		return word[0]
	elif todosIugales(sepa2):
		return multigram(sepa[0])
	else:
		return word
	
while True:
	try:
		word = input().strip()
		# print(multigram(word), 0)
		res = multigram(word)
		if res == word:
			print(-1)
		else:
			print(res)
	except Exception as e:
		# print(e)
		break
