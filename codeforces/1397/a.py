from collections import defaultdict
for t in range(int(input())):
	de = defaultdict(int)
	n = int(input())
	for _ in range(n):
		for ch in input().strip():
			de[ch]+=1
	print("YES" if all(v%n==0 for v in de.values()) else "NO")