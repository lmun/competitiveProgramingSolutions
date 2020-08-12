n,m,x,y = map(int, input().split())
a,b = x,y
print(a,b)
for i in range(1,m+1):
	if i!=b:
		print(a,i)
b = m
co = 0
for i in range(1,n+1):
	if i==x:
		continue
	if co%2==0:
		for j in reversed(range(1,m+1)):
			print(i,j)
	else:
		for j in range(1,m+1):
			print(i,j)
	co += 1