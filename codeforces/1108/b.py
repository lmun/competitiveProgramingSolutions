n = int(input())
nums = [int(x) for x in input().split()]
ma = max(nums)
re = [False]*(ma+1)
rest = []
for nu in nums:
	if ma%nu == 0 and  not re[nu]:
		re[nu] = True
	else:
		rest.append(nu)
print(ma, max(rest))