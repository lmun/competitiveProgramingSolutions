#x,y=map(int,input().split())
lim=1000000
cri=[0]*lim
pri=list()
priset=set()
for i in range(2,lim):
	if cri[i]==0:
		pri.append(i)
		priset.add(i)
		for j in range(i*i,lim,i):
			cri[j]=i
pos=[0]*len(pri)
mx,ma=0,0
def isprim(n):
	if n in pri:
		return True
	else:
		for p in pri:
			if n%p==0:
				return False
		return True
for i in range(len(pri)):
	#print(i)
	for j in range(len(pri)-i):
		pos[j]+=pri[j+i]
		if pos[j] > lim:
			#break
			pass
		if isprim(pos[j]) and i>0:
			print(pos[j],i)
			mx,ma=pos[j],i
			break
	if i==0:
		continue
print(mx,ma)

