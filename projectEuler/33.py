n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
a = n
po=10**(k)
for i in range(10**(a-1),10**(a)):
	for j in range(i+1,10**(a)):
		wi=str(i)
		wj=str(j)
		ri=""
		rj=""
		for t in wi:
			if t not in wj:
				ri+=t
		for t in wj:
			if t not in wi:
				rj+=t
		if i%10!=0 and len(rj)>0 and len(ri)==n-k and int(rj)*i==int(ri)*j:
			print(i,j)