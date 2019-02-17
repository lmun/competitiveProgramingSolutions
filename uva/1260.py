for t in range(int(input())):
	n = int(input())
	nums = [int(x) for x in input().split()]
	res = 0
	for i in range(1, n):
		for j in range(i):
			if nums[j] <= nums[i]:
				res += 1
	print(res)
