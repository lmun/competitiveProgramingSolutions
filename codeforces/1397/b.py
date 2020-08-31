n=int(input())
li = [int(x) for x in input().split()]
li.sort()
def aux(nu):
	ee = 0
	sue = 1
	for i in range(len(li)):
		ee += abs(sue-li[i])
		sue*=nu
	return ee
def aux2(nu, limi):
	ee = 0
	sue = 1
	for i in range(len(li)):
		ee += abs(sue-li[i])
		if ee> limi:
			return True
		sue*=nu
	return ee > limi
def tata(n):
	return aux(n+1)>aux(n)
if n > 32:
	n0, n1 = sum(li), aux(1)
	if aux2(2,n1):
		print(min(n0,n1))
	else:
		print(2)
else:
	lo, hi = 0, 1
	while not tata(hi):
		hi*=2
	while lo<hi:
		mid = (lo+hi)//2
		if tata(mid):
			hi = mid
		else:
			lo = mid+1
	print(aux(lo))