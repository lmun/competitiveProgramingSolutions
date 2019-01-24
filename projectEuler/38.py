n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
for i in range(2,n):
	s=""
	j=1
	asd=False
	while len(s)<k:
		s+=str(i*j)
		j+=1
	if len(s)==k:
		asd=True
		for h in range(1,k+1):
			if str(h) not in s:
				if i==18:
					print(s,h)
				asd=False
	if asd:
		print(i)
		print(s)