limit=5000
fib=[1,1]
res=[]
act=2
mlen=0
while mlen < limit:
	if len(str(fib[act%2]))==mlen+1:
		mlen=mlen+1
		res.append(act)
	fib[(act+1)%2]=sum(fib)
	act+=1

for _ in range(int(input())):
	s = int(input())
	print(res[s-1])
	#for x in range(s):
		#print(str(x)+" - "+str(res[x]))
