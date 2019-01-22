tot = 0
for i in range(int(input())):
	x, y = map(float, input().split())
	tot += (x * y)
print(tot)