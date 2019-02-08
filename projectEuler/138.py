from math import sqrt
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def iscuad(a):
	lo = 1
	hi = 1
	while a > hi*hi:
		hi *= 2
	while hi > lo:
		mid = (hi+lo)//2
		if mid * mid == a:
			return True
		elif mid*mid < a:
			lo = mid + 1
		else:
			hi = mid
	return lo *lo == a
# for i in range(1, 100000):
	# wa = 20*i*i
	# if wa in se:
		# print(0)
		# print(i, (-4*i+sqrt(wa))/2)
		# print(i, (-4*i-sqrt(wa))/2)
	# if wa+4 in se:
		# print(+4)
		# print(i, (-4*i+sqrt(wa+4))/2)
		# print(i, (-4*i-sqrt(wa+4))/2)
	# if wa -4 in se:
		# print(-4)
		# print(i, (-4*i+sqrt(wa-4))/2)
		# print(i, (-4*i-sqrt(wa-4))/2)
resp = []
ini = 1
for _ in range(200):
	we = 20*ini*ini
	if iscuad(we+4):
		a = abs((-4*ini+sqrt(we+4))//2)
		b = abs((-4*ini-sqrt(we+4))//2)
	if iscuad(we -4):
		 a = abs((-4*ini+sqrt(we-4))//2)
		 b = abs((-4*ini-sqrt(we-4))//2)
	#print(ini, max(a, b))
	resp.append(ini)
	ini = int(max(a,b))
#print(resp)
res = 0
for i in range(12):
	a = resp[i]
	b = resp[i+1]
	res += (a*a+b*b)
print(res)
