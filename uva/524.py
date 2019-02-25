from itertools import permutations
m = 50
cri = [0]*m
for i in range(2,m):
	if cri[i] == 0:
		for j in range(i*i, m, i):
			cri[j] = i
def esprimo(n):
	return cri[n] == 0

def ayu(li, n):
	if len(li) == n and esprimo(li[-1] + 1):
		print(" ".join(map(str,li)))
	else:
		for i in range(2, n+1):
			if i not in se and esprimo(i+li[-1]):
				se.add(i)
				ayu(li+[i], n)
				se.remove(i)
t = 1
while True:
	try:
		n = int(input())
		if t > 1:
			print()
		print("Case {}:".format(t))
		se = set()
		se.add(1)
		ayu([1],n)
		t += 1
	except Exception as e:
		#print(e)
		break