from math import sqrt
for i in range(int(input())):
	wo = input().strip()
	l = int(sqrt(len(wo)))
	res = ''
	for j in reversed(range(l)):
		for k in range(l):
			res += wo[k*l+j]
	print(res)
