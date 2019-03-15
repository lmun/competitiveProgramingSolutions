tt = False
while True:
	n = int(input())
	if n == 0:
		break
	nums = [int(x) for x in input().split()]
	while len(nums)<n:
		nums += [int(x) for x in input().split()]
	nums.sort()
	bags = []
	for nu in reversed(nums):
		if bags:
			lo, hi = 0, len(bags)-1
			while hi> lo:
				mid = (lo+hi)//2
				if bags[mid] > nu:
					hi = mid
				else:
					lo = mid + 1
			if bags[hi] > nu:
				bags[hi] = nu
			else:
				bags.append(nu)
		else:
			bags.append(nu)
	nb = len(bags)
	resp = [[] for _ in range(nb)]
	for i, v in enumerate(nums):
		resp[i%nb].append(str(v))
	if tt:
		print()
	else:
		tt = True
	print(nb)
	for r in resp:
		print(' '.join(r))
	# print(resp)