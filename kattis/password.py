pas = []
for i in range(int(input())):
	a, b = input().split()
	pas.append((float(b), a))
pas.sort(reverse=True)
ind = 1
res = 0
for x, y in pas:
	res += ind * x
	ind += 1
print(res)
