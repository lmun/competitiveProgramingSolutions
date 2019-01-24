t = int(input())
n = (2*t - 2)
palas = [(input().strip(), i) for i in range(n)]
res = ['x' for _ in range(n)]
s = ""
p = ""
for ta in palas:
	# print(w, s, p)
	w = ta[0]
	if len(w) > len(s):
		s = w
	elif len(w) == len(s):
		p = w

sopas = sorted(palas, key=lambda x:len(x[0]))
#print(p, s)
for wa in range(0,len(sopas), 2):
	u = sopas[wa][0]
	o = sopas[wa+1][0]
	# print(u, o)
	if not s.endswith(u) and not s.endswith(o):
		s, p = p, s
		break
	elif not p.startswith(u) and not p.startswith(o):
		s, p = p, s
		break
if p[1:] != s[:-1]:
	s, p = p, s
for wa in range(0,len(sopas), 2):
	u = sopas[wa][0]
	o = sopas[wa+1][0]
	if p.startswith(u) and s.endswith(o):
		res[sopas[wa][1]] = 'P'
		res[sopas[wa+1][1]] = 'S'
	else:
		res[sopas[wa][1]] = 'S'
		res[sopas[wa+1][1]] = 'P'
print(''.join(res))
