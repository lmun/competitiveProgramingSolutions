n = int(input())
nums = [int(x) for x in reversed(input().split())]
for i, nu in enumerate(nums):
	if nu != nums[0]:
		print(n-i)
		break
