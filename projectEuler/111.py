def ispandi(num):
	arr = [0] * 10
	x = num
	while x > 0:
		arr[x % 10] += 1
		x //= 10
	for a in arr:
		if a > 1:
			return False
	if arr[0] == 1:
		return False
	return True

def numify(num):
	arr = [0] * 10
	x = num
	while x > 0:
		arr[x % 10] += 1
		x //= 10
	res = 0
	for i in reversed(range(10)):
		res *= 2
		if arr[i] == 1:
			res += 1
	return res

tot = 0
def nono(num, ind, acc):
	global tot
	# print('-', num, ind, acc)
	for i in range(ind, 1027):
		ilala = num & i
		if ilala == 0 and lala[i] > 0:
			olala = num | i
			if olala == 1022:
				tot += acc * lala[i]
			else:
				# print(ilala, num, i, olala)
				nono(olala, i + 1, acc * lala[i])
	# print('+', num, ind, acc)

print(ispandi(123456789),numify(123456789))
n = 8
m = 10 ** n
cri = [0] * m
pri = []
numi = []
lala = [0] * 1030
for i in range(2, m):
	if cri[i] == 0:
		if ispandi(i):
			pri.append(i)
			ni = numify(i)
			lala[ni] += 1
		for j in range(i * i, m, i):
			cri[j] = i
for i in range(len(lala)):
	p = lala[i]
	if p > 0:
		nono(i, i + 1, lala[i])
	# print(i)

print(tot)
