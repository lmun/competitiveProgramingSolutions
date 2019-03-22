n = int(input())
nums = [int(x)-1 for x in input().split()]
i = 0
m = -1
res = 0
while i < n:
	res += 1
	m = max(nums[i], m)
	while i < m:
		i += 1
		m = max(nums[i], m)
	i += 1
print(res)
