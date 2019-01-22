def nono7(n, r):
	wa = a7[r % 10]
	#print(wa, wa * n + r)
	#de = (wa * n + r) % 10
	re = (wa * n + r)//10
	res = 1
	while re > 0:
		res += 1
		wa = a7[re % 10]
		re = (wa * n + re)//10
	return res


def nono3(n, r):
	wa = a3[r % 10]
	#print(wa, wa * n + r)
	#de = (wa * n + r) % 10
	res = 1
	re = (wa * n + r)//10
	while re > 0:
		res += 1
		wa = a3[re % 10]
		re = (wa * n + re)//10
	return res

def nono1(n, r):
	res = 1
	wa = a1[r % 10]
	r = (wa * n + r)//10
	while r > 0:
		res += 1
		wa = a1[r % 10]
		r = (wa * n + r)//10
	return res


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
#no1 = 1
#no3 = 3
#no7 = 7
no1 = 1000001
no3 = 1000003
no7 = 1000007
maxa = 0
for i in range(10):
	a = nono1(no1, 0)
	#print(no1, a)
	b = nono3(no3, 0)
	#print(no3, b)
	c = nono7(no7, 0)
	#print(no7, c)
	print(no1, a)
	print(no3, b)
	print(no7, c)
	d = max(a,b,c)
	if d > 1000000:
		print(no1, no3, no7, d)
		break
	no1 += 10
	no3 += 10
	no7 += 10
	#tt = int(a)
	#print(i, tt, i*tt, b)
