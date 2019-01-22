def nono7(n, r):
	wa = a7[r % 10]
	#print(wa, wa * n + r)
	de = (wa * n + r) % 10
	re = (wa * n + r)//10
	if re > 0:
		pl, ok = nono7(n, re)
		return  pl+ str(wa),ok+1
	return str(wa), 1

def nono3(n, r):
	wa = a3[r % 10]
	#print(wa, wa * n + r)
	de = (wa * n + r) % 10
	re = (wa * n + r)//10
	if re > 0:
		pl, ok = nono3(n, re)
		return  pl+ str(wa),ok+1
	return str(wa), 1

def nono1(n, r):
	wa = a1[r % 10]
	#print(wa, wa * n + r)
	de = (wa * n + r) % 10
	re = (wa * n + r)//10
	if re > 0:
		pl, ok = nono1(n, re)
		return  pl+ str(wa),ok+1
	return str(wa), 1


a3 = [0]*10
a1 = [0]*10
a7 = [0]*10
tre = 0
uno = 0
sie = 0
for i in range(10):
	#a1[i] = (11 - uno) % 10
	a1[(11 - uno) % 10] = i
	a3[(11 - tre) % 10] = i
	#a3[i] = (11 - tre) % 10
	a7[(11 - sie) % 10] = i
	uno = (uno + 1) % 10
	tre = (tre + 3) % 10
	sie = (sie + 7) % 10
no1 = 1
no3 = 3
no7 = 7
for i in range(10):
	a, b = nono1(no1, 0)
	print(no1, b, int(a))
	a, b = nono3(no3, 0)
	print(no3, b, int(a))
	a, b = nono7(no7, 0)
	print(no7, b, int(a))
	no1 += 10
	no3 += 10
	no7 += 10
	#tt = int(a)
	#print(i, tt, i*tt, b)
