n = int(input())
nombres = list(input().split())
sco = input()
wd, wo = 2, 0
bo, bd = 1, 3
que = list(range(n))
act = 4
mat = [[0]*n for _ in range(n)]
for c in sco:
	if c == 'W':
		wd, wo = wo, wd
		que.append(bd)
		bd, bo = bo, que[act]
		act +=1
		mat[wo][wd] += 1
		mat[wd][wo] += 1
	else:
		bd, bo = bo, bd
		que.append(wd)
		wd, wo = wo, que[act]
		act +=1
		mat[bo][bd] += 1
		mat[bd][bo] += 1
for m in mat:
	print(m)
