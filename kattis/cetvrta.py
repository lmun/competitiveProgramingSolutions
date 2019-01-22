def difi(n):
	if n[0] == n[1]:
		return n[2]
	elif n[0] == n[2]:
		return n[1]
	return n[0]


x = []
y = []
for _ in range(3):
	a, b = map(int, input().split())
	x.append(a)
	y.append(b)
print(difi(x), difi(y))

