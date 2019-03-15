def tipo1(ind):
	return s == t[ind:ind+ls]
def tipo2(ind):
	pu = True
	j = ind
	for i in range(ls):
		if j == lt:
			continue
		if s[i] == t[j]:
			j += 1
			continue
		elif pu:
			pu = False
			continue
		break
	else:
		return True
	return False
def tipo3(ind):
	pu = True
	j = 0
	for i in range(ls+1):
		if j == ls:
			continue
		if t[i+ind] == s[j]:
			j += 1
			continue
		if pu:
			pu = False
			continue
		break
	else:
		return True
	return False
try:
	while True:
		s, t = input().split()
		ls = len(s)
		lt = len(t)
		t1 = sum(tipo1(x) for x in range(lt-ls+1))
		t2 = sum(tipo2(x) for x in range(lt-ls+2))
		t3 = sum(tipo3(x) for x in range(lt-ls))
		print(t1,t2,t3)
except Exception as e:
	pass
