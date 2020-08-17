from itertools import accumulate
from collections import defaultdict
for t in range(int(input())):
	n = int(input())
	v = input().strip()
	di = defaultdict(int)
	val = [int(c) for c in v]
	acc = list(accumulate(val))
	per = [acc[i]-i for i in range(n)]
	res = 0
	for ee in reversed(per):
		res += di[ee]
		di[ee] += 1
	res += di[1]
	print(res)
	# print(di)
	# print(val)
	# print(acc)
	# print(per)
