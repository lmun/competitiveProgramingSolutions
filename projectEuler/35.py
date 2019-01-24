m=int(input())
cri=[0]*m
pri = set()
for i in range(2,m):
	if cri[i] == 0:
		cri[i] = i
		pri.add(i)
		for j in range(i*i,m,i):
			cri[j] = i
res=0
for p in pri:
	s=str(p)
	ls=len(s)
	s+=s
	circu=True
	for i in range(ls):
		if int(s[i:i+ls]) not in pri:
			circu = False
			break
	if circu:
		#print(p)
		res+=1
print("res =",res)