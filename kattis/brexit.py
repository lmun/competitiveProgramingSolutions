c, p, x, l  = map(int, input().split())
adj = [[] for _ in range(c)]
inunion = [True]*c
partners = [0]*c
for _ in range(p):
	a, b = map(int, input().split())
	a-=1
	b-=1
	adj[a].append(b)
	adj[b].append(a)
	partners[a] += 1
	partners[b] += 1
leaves = [l-1]
while leaves:
	lea = leaves.pop()
	inunion[lea] = False
	for aa in adj[lea]:
		if inunion[aa]:
			partners[aa] -= 1
			if partners[aa]*2 <= len(adj[aa]):
				leaves.append(aa)
print('stay' if inunion[x-1] else 'leave')
