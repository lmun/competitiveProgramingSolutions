n, m, k = map(int,input().split())
nums = list(map(int, input().split()))
act = 0
cjs = 1
i = n-1
while i >= 0 and cjs <= m:
#	print(i, act, cjs)
	if act + nums[i] > k:
		if cjs < m:
			cjs += 1
			act = nums[i]
			i -= 1
		else:
			break
	else:
		act += nums[i]
		i -= 1
print(n-i-1)
#print(n,i)