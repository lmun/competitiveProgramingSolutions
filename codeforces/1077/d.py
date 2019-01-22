n, k = map(int, input().split())
nums = list(map(int, input().split()))
pares = {}
for n in nums:
	pares[n] = pares.get(n, 0) + 1
li = []
for p in pares:
	li.append((pares[p], p))

li.sort(reverse=True)
ini = 0
fin = 10**6
while fin > ini:
	mid = (fin + ini + 1)//2
	su = 0
	for e in li:
		po = e[0]//mid
		if po == 0:
			break
		su += po
		if su >= k:
			break
	if su >= k:
		ini = mid
	else:
		fin = mid - 1
# print(ini, fin)
res = []
p = 0
for i in range(min(k, len(li))):
	if p == k:
		break
	aa = li[i][0]//ini
	for qq in range(aa):
		if p == k:
			break
		res.append(li[i][1])
		p += 1
# print(p, k)
print(' '.join(map(str, res)))
