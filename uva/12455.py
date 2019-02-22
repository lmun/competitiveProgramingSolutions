for t in range(int(input())):
	n = int(input())
	p = int(input())
	b = [int(x) for x in input().split()]
	s = set()
	s.add(0)
	for l in b:
		s |= set(map(lambda x: l + x, s))
	print("YES" if n in s else "NO")