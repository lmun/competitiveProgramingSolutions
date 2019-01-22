se = set()
limi = 10**12
se.add(1)
#limi = 50
for b in range(2, 10000000):
	a = b*b+b+1
	while a < limi: 
		se.add(a)
		a *= b
		a += 1
print(sum(se))
#print(se)