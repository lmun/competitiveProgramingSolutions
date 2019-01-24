import time
t0=time.time()
pri=set()
pril=list()
limi=20000000
cri=[0]*limi
for i in range(2,limi):
	if cri[i]==0:
		pri.add(i)
		pril.append(i)
		for j in range(i*i,limi,i):
			cri[j]=1
def esprimo(n):
	if n < limi:
		return cri[n]==0
	for nunu in pril:
		if nunu*nunu > n:
			break
		if n%nunu==0:
			return False
	return True
t1=time.time()
t=1
p=0
i=1
wawa=int(input())
t3=time.time()
while True:
	i+=2
	for j in range(4):
		if esprimo(i*i-j*(i-1)):
			p+=1
		t+=1
	#print(i,p,t,p/t)
	if 100*p < wawa*t:
		print(i)
		break;
t2=time.time()
print(t1-t0,t2-t3)