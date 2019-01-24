mr=0
for i in range(4,100000):
	r=0
	for j in range(i+1,2*i+1):
		if i*j%(j-i)==0:
			r+=1
	if r>mr:
		mr=r
		print(i,r)
	if r > 1000:
		print(i,r)
		break