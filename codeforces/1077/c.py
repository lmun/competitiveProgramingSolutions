n = int(input())
nums = list(map(int, input().split()))
senums = {}
for num in nums:
	senums[num] = senums.get(num, 0) + 1
tot = sum(nums)
res = []
for i in range(n):
	x = tot -nums[i]
	if x % 2 == 0 and x//2 in senums:
		if x//2 == nums[i] and senums[nums[i]] == 1:
			continue
		res.append(i + 1)
print(len(res))
print(' '.join(list(map(str,res))))
