from functools import reduce
from collections import Counter
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

def todosIugales(x):
	return all(x[0] == i for i in x)

def multigram(word):
	if len(word) == 1:
		return word
	mapa = dict(Counter(word))
	copi = reduce(gcd, mapa.values())
	if copi == 1:
		return word
	elif copi == len(word):
		return word[0]
	sepa = [word[g:g + len(word)//copi] for g in range(0, len(word), len(word)//copi)]
	sepa2 = [sorted(s) for s in sepa]
	if todosIugales(sepa2):
		return multigram(sepa[0])
	else:
		return word

word = input().strip()
res = multigram(word)
if res == word:
	print(-1)
else:
	print(res)
