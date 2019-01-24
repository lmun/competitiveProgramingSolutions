from math import sqrt

def isPenta(num):
	nu=24*num+1
	#print(nu)
	rai=int(sqrt(nu))
	return rai*rai==nu and rai%6==5


penta=list()
coco=0
for i in range(1,1000000):
	penta.append((i*(3*i-1))//2)
	#pent.add((i*(3*i-1))//2)
	for k in range(i-1,0,-1):
		if isPenta(penta[i-1]-penta[k-1]) and isPenta(penta[k-1]+penta[i-1]):
			print(penta[i-1]-penta[k-1],coco)
			coco+=1
			if coco > 12:
				exit(0)
