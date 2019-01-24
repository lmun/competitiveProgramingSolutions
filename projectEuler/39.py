m=0
for p in range(3,1000):
	r=0
	for i in range(1,p):
		for j in range(i,p-i):
			a=i*i+j*j
			b=(p-i-j)*(p-i-j)
			if a==b:
				r+=1
			elif a > b:
				break
	if r >= m:
		print(p,r)
		m=r