for t in range(int(input())):
	nums = [int(x) for x in input().split()]
	deg = nums[0]
	coefs = nums[1:]
	d = int(input())
	k = int(input())
	lo = 0
	hi = 1
	while d*hi*(hi+1)//2 < k:
		hi *= 2
	while hi > lo:
		mid = (hi+lo)//2
		if d*mid*(mid+1)//2 < k:
			lo = mid + 1
		else:
			hi = mid
	n = 1
	res = 0
	for co in coefs:
		res += co*n
		n *= lo
	print(res)
