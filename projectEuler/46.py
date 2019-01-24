from math import sqrt

nums=1000000
cri=[0]*nums
gol=[0]*nums
pri=list()
for i in range(2,nums):
	if cri[i]==0:
		pri.append(i)
		for j in range(i*i,nums,i):
			cri[j]=i
for i in range(1,int(sqrt(nums))+2):
	for p in pri:
		x=p+2*i*i
		if x < nums:
			gol[x]+=1
		else:
			break
"""
for i in range(nums):
	if i%2==1 and cri[i]!=0 and gol[i]==0:
		print(i)
		break
"""
for _ in range(int(input())):
	print(gol[int(input())])