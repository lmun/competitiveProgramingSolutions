from itertools import permutations
for t in range(int(input())):
	rn = range(int(input()))
	mat = [[int(x) for x in input().split()] for _ in rn]
	print(min(sum(mat[x][y] for x, y in zip(rn, p)) for p in permutations(rn)))
