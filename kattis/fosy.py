n = int(input())
nombres = list(input().split())
sco = input()
wd, wo = 2, 0
bo, bd = 1, 3
que = list(range(4, n))
act = 0
la = 'x'
ini = [0]
lar = 0
lara = 0
i = 0
for s in sco:
	if s == la:
		lara += 1
	else:
		lara = 1
	if lar == lara:
		ini.append(i+1-lara)
	if lara > lar:
		ini = [i+1-lara]
		lar = lara

	# print(s, la, lara, lar)
	# print(ini)
	la = s
	i += 1
# print(ini)
j = 0
ni = 0
for c in sco:
	if ni >= len(ini):
		break
	if c == 'W':
		if act == ini[ni]:
			if act == 0:
				print(nombres[wo], nombres[wd])
			else:
				print(nombres[wd], nombres[wo])
			ni += 1
		wd, wo = wo, wd
		que.append(bd)
		bd, bo = bo, que[act]
		act +=1
	else:
		if act == ini[ni]:
			if act == 0:
				print(nombres[bo], nombres[bd])
			else:
				print(nombres[bd], nombres[bo])
			ni += 1
		bd, bo = bo, bd
		que.append(wd)
		wd, wo = wo, que[act]
		act +=1
