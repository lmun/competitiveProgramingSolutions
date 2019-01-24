def samedigi(a,b):
	sa=str(a)
	sb=str(b)
	if len(sa)!= len(sb):
		return False
	conb=[0]*10
	for d in str(a):
		conb[int(d)]+=1
	for d in str(b):
		conb[int(d)]-=1
	for i in range(10):
		if conb[i]!=0:
			return False
	return True

nums=1000000
cri=[0]*nums
pri=list()
n,k=map(int,input().split())
for i in range(2,nums):
	if cri[i]==0:
		if i > 999:
			pri.append(i)
		for j in range(i*2,nums,i):
			cri[j]+=1

for i in range(1,len(pri)):
	for j in range(i):
		if pri[j]>n:
			break
		if samedigi(pri[i],pri[j]) and pri[i]*2-pri[j] in pri and samedigi(pri[i]*2-pri[j],pri[i]):
			if k==3:
				print(str(pri[j])+str(pri[i])+str(pri[i]*2-pri[j]))
			elif k==4 and pri[i]*3-2*pri[j] in pri and samedigi(pri[i]*3-2*pri[j],pri[i]):
				print(str(pri[j])+str(pri[i])+str(pri[i]*2-pri[j])+str(pri[i]*3-2*pri[j]))