def indi(a):
	return ord(a)-ord('A')


a = [[0]*26 for _ in range(26)]
b = [[0]*26 for _ in range(26)]
for i in range(int(input())):
	word = input().strip()
	# print(word)
	# print((word[0]), (word[-1]))
	# print(indi(word[0]), indi(word[-1]))
	a[indi(word[0])][indi(word[-1])] += 1
for i in range(26):
	for j in range(26):
		for k in range(26):
			if k==j and i == j:
				b[i][j] += (a[i][k]-1) * a[k][j]
			else:
				b[i][j] += a[i][k] * a[k][j]
tot = 0
for i in range(26):
	for j in range(26):
		tot += b[i][j]
		if b[i][j] > 0:
			print(i, j, b[i][j])
print(tot)