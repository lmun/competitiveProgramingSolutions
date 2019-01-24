def invinum(n):
	r=0
	while n>0:
		r*=10
		r+=n%10
		n//=10
	return r
ma=int(input())
wa={}
res,re=0,0
for i in range(1,ma+1):
	#a=invinum(i)
	b=i
	for c in range(60):
		binb=invinum(b)
		if b == binb:
			#print(b)
			if b==121:
				#print(i)
				pass
			if b in wa:
				wa[b]+=1
				if wa[b] >= re:
					res,re=b,wa[b]
			else:
				wa[b]=1
			break
		else:
			b+=binb

print(res,re)