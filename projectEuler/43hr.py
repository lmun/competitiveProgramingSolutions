def uni(n):
	w=str(n)
	s=set(w)
	return len(w)==len(s)

n=int(input())
posi=set()
for i in range(n+1):
	for j in range(n+1):
		for k in range(n+1):
			if uni(str(i)+str(j)+str(k)):
				posi.add(str(i)+str(j)+str(k))

pares=[2,3,5,7,11,13,17]
i=3
for x in pares:
	if i > n:
		break
	i+=1
	nuse=set()
	for po in posi:
		for t in range(n+1):
			e=po+str(t)
			if uni(e) and (int(e[-3:]))%x==0:
				#print(t,e,po,x)
				#print(e[-3:])
				nuse.add(e)
	posi=nuse
resu=0
for p in posi:
	#print(p)
	resu+=int(p)
print(resu)