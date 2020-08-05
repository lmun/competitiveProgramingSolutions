def iscuad(a):
	lo = 1
	hi = 1
	while a > hi * hi:
		hi *= 2
	while hi > lo:
		mid = (hi + lo)//2
		if mid * mid < a:
			lo = mid + 1
		else:
			hi = mid
	return lo if lo * lo == a else 0

re, i = 0, 1
for _ in range(12):
	we = 5 * i * i
	m4 = iscuad(we + 1)
	l4 = iscuad(we - 1)
	re += i * i
	if m4:
		i = m4 + 2 * i
	if l4:
		i = l4 + 2 * i
	re += i * i
	# print(_+1,re, len(str(re)))
print(re)
