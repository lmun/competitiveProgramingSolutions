def hanoi(n, a, b, c):
	if len(a) + len(b) + len(c) == 0:
		return 0
	if len(a) > 0 and a[0] == n:
		return 2**(n-1) + hanoi(n-1, a[1:], c, b)
	if len(c) > 0 and c[0] == n:
		return hanoi(n-1, b, a, c[1:])
	return float("-inf")


t = [[] for _ in range(3)]
for i in range(3):
	t[i] = list(map(int, input().split()))[1:]
ll = sum(len(c) for c in t)
hano = hanoi(ll, t[0], t[1], t[2])
print(hano if hano >=0 else 'No')
