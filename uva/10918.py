# kattis tritilting
res = [0]*40
acc = [0]*40
res[2] = 3
for i in range(4, 40, 2):
	res[i] = res[i-2]*3 + 2*(acc[i-2]+1)
	acc[i] = res[i-2]+acc[i-2]
res[0] = 1
while True:
	n = int(input())
	if n == -1:
		break
	print(res[n])
