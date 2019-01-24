n = int(input())
re = [int(x)%2 for x in input().split()]
su = 0
ba = 0
for i in range(0, n-1, 2):
	if re[i] != re[i+1]:
		if re[i] == 0:
			su += 1
		else:
			ba += 1
posi = su == ba
if n%2 == 1:
	if su + 1 == ba and re[n-1] == 0:
		posi = True
	if ba + 1 == su and re[n-1] == 1:
		posi = True
if not posi:
	print("NO")
else:
	print("YES")
