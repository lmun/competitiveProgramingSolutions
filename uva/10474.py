t = 1
while True:
	n, q = map(int, input().split())
	if n == 0 and q == 0:
		break
	nums = [int(input()) for _ in range(n)]
	nums.sort()
	print("CASE# {}:".format(t))
	for _ in range(q):
		f = int(input())
		lo, hi = 0, n-1
		while hi> lo:
			mid = (hi+lo)//2
			if nums[mid] < f:
				lo = mid+1
			else:
				hi = mid
		if nums[hi] == f:
			print("{} found at {}".format(f, hi+1))
		else:
			print("{} not found".format(f))
	t += 1