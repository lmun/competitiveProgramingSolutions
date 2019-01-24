n=int(input())
s=set()
for i in range(2,n+1):
	for j in range(2,n+1):
		s.add(i**j)
print(len(s))