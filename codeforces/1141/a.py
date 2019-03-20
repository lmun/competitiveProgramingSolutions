n, m = map(int, input().split())
res = 0
if m%n!=0:
	print(-1)
else:
	dd = m//n
	while dd%2 == 0:
		dd//=2
		res+=1
	while dd%3==0:
		dd//=3
		res+=1
	print(res if dd == 1 else -1)