se=set()
c=0
for _ in range(int(input())):
	x,y=input().split()
	if x not in se and c < 12:
		print(x,y)
		c+=1
	se.add(x)