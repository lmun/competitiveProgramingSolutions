def a(n,s):
	if sum(map(int,str(n)))<=s:
		return 0
	return 10-n%10+10*a(1+n//10,s) if n%10 else 10*a(n//10,s)
for t in range(int(input())):
	print(a(*map(int,input().split())))