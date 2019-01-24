#!/usr/bin/python3.5
l = list()
for _ in range(40):
	l.append(input().split(','))
repe = [i for i in range(40)]
aho = 0
vert = list()
for i in range(40):
	for j in range(i):
		if l[i][j] != '-':
			vert.append((int(l[i][j]),i,j))

vert.sort(key = lambda x : x[0])

def getRepe(a):
	return a if repe[a] == a else getRepe(repe[a])

for v,i,j in vert:
	ri = getRepe(i)
	rj = getRepe(j)
	if ri == rj:
		aho += v
	else:
		repe[ri] = rj

print(aho)