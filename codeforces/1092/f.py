def waa(x, y):
	aa = nono.get((x, y), -1)
	if aa != -1:
		return aa
	res = cost[y]
	acc = cost[y]
	for r in mat[y]:
		if r == x:
			continue
		res += waa(y, r)
		res += nini.get((y,r))
		acc += nini.get((y,r))
	nono[(x, y)] = res
	nini[(x, y)] = acc
	return res


n = int(input())
cost = [int(x) for x in input().split()]
mat = [[] for _ in range(n)]
for i in range(n-1):
	x, y = map(lambda x:int(x)-1, input().split())
	mat[x].append(y)
	mat[y].append(x)
nono = {}
nini = {}
for m in range(len(mat)):
	for y in mat[m]:
		waa(m ,y)
if n == 1:
	print(0)
else:
	print(max(nono.values()))
