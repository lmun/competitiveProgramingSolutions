mod=1000000007
for _ in range(int(input())):
	s = int(input())
	res=(2*(s+1)*(s+2)*(s+3))//3
	res-=((7*(s+1)*(s+3))//2)
	res+=8*(s+1)
	print((res-3)%mod)