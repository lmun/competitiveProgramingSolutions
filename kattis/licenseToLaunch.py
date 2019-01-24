n = int(input())
nums = [int(x) for x in input().split()]
mi = 10**18
res = 0
for i in range(n):
	if nums[i] < mi:
		res = i
		mi = nums[i]
print(res)
