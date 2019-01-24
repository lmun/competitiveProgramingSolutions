def testi(n):
	a=str(n)
	for i in range(5,len(a)):
		if i%2==0 and a[i]!=(i//2)+1:
			return False
	return True
def ttt(n):
	if n%10==9 and (n//100)%10==8 and (n//10000)%10==7 and (n//1000000)%10==6 and (n//100000000)%10==5 and (n//10000000000)%10==4 and (n//1000000000000)%10==3 and (n//100000000000000)%10==2:
		return True
for i in range(100000000,10000000000):
	if ttt(i*i):
		print(i*i,i)