cand = input().strip()
counts = [[] for _ in range(300)]
for i in range(len(cand)):
	counts[ord(cand[i])].append(i)
#print(counts)
def findi(mi, ch):
	#print(mi,ch)
	eli = counts[ord(ch)]
	l = 0
	h = len(eli)-1
	while h > l:
		mid = (h+l)//2
		if eli[mid] <= mi:
			l = mid + 1
		else:
			h = mid
	return eli[h]

for q in range(int(input())):
	w = input().strip()
	ini = findi(-1, w[0])
	a = ini
	posi = True
	for i in range(1, len(w)):
		n = findi(a, w[i])
		if n > a:
			a = n
		else:
			posi = False
			break
	if posi:
		print("Matched {} {}".format(ini, a))
	else:
		print("Not matched")


