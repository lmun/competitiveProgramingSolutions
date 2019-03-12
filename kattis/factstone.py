from math import log
n = 1
su = 0
resp = []
for nunu in range(23):
	while su + log(n, 2) < 1<<nunu:
		su += log(n, 2)
		n += 1
	resp.append(n-1)
# print(resp)
while True:
	y = int(input())
	if y == 0:
		break
	y //= 10
	y -= 194
	print(resp[y])
	
