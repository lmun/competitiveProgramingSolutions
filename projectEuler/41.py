def ispandi(n):
	t=len(str(n))
	nums=[0]*11
	while n > 0:
		nums[n%10]+=1
		n//=10
	i=1
	while nums[i]==1:
		i+=1
	return i-1==t


m=10**7
cri=[0]*m
p=list(-1)
for i in range(2,m):
	if cri[i]==0:
		if ispandi(i):
			#print(i)
			p.append(i)
		for j in range(i*i,m,i):
			cri[j]=i
for _ in range(int(input())):
	num=int(input())
	l=0
	h=len(p)-1
	while h>l:
		mid=(h+l)//2
		if p[mid] <= num:
			l=mid+1
		else:
			h=mid
	if p[h] > num:
		print(-1)
	else:
		print(p[h])