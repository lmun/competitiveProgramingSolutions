a=1
b=1
res=0
for i in range(int(input())):
	nb=b+a
	a=nb+b
	b=nb
	if len(str(a))>len(str(b)):
		print(i)
		res+=1
print(res)