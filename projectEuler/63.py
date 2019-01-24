i=int(input())
count=0
if i%1000==0:
	print(i,count)
j=1
while True:
	a=j**i
	sa=str(a)
	if len(sa) > i:
		break
	if len(sa) == i:
		print(i,j,sa)
		count+=1
	j+=1
	
