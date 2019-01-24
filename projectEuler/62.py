def hash(n):
	return ''.join(sorted(str(n)))
n,tt=map(int,input().split())
m={}
wa={}
#h=hash(589323567104)
for i in range(n):
	w=hash(i*i*i)
	if w in m:
		m[w]+=1
	else:
		m[w]=1
		wa[w]=i
	#if w==h:
		#print(i,i*i*i,m[w])
res=list()
for k,v in m.items():
	if v==tt:
		res.append(wa[k]**3)
res.sort()
for r in res:
	print(r)