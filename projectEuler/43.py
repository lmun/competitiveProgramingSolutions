def uni(n):
	w=str(n)
	s=set(w)
	return len(w)==len(s)
pares=[(17,0),(13,0),(11,0),(7,0),(5,1),(3,2),(2,1),(1,1)]
posi=set()
for i in range(1,100):
	if uni(i):
		posi.add(str(i))
for x,y in pares:
	nuse=set()
	for po in posi:
		for t in "0123456789":
			e=t+po
			if uni(e) and (int(e[:3]))%x==0:
				#print(t,e,po,x)
				nuse.add(e)
	posi=nuse
resu=0
for pala in posi:
	resu+=int(pala)
print(resu)
