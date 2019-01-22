word = input()
res = []
for c in word:
	if len(res) == 0 or c != res[-1]:
		res.append(c)
print(''.join(res))
