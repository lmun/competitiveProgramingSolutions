nume=int(input())
limite=5000000
sieve=[0]*limite
sieve[1]=1
primos=[]
for i in range(2,limite):
	if sieve[i]==0:
		sieve[i]=i
		primos.append(i)
		#print(i)
		for j in range(i*i,limite,i):
			sieve[j]=i
posibles=[]
for i in range(len(primos)):
	if primos[i]>nume:
		break
	for j in range(-nume,nume,1):
		este=1+j+primos[i]
		if sieve[este]==este:
			posibles.append((primos[i],j))
			#print(primos[i],j)
n=2
while len(posibles)>0:
	alt=[]
	for x,y in posibles:
		este=n*n+n*y+x
		if este > 0 and sieve[este]==este:
			alt.append((x,y))
	if len(alt)==0:
		a,b=posibles[0]
		print(b,a)
	posibles=alt
	n+=1
	