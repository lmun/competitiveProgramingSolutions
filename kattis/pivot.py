n = int(input())
nums = [int(x) for x in input().split()]
posi = [1]*n
maxi = nums[0]
mini = nums[-1]
for i in range(1, n):
	if nums[i] > maxi:
		maxi = nums[i]
	else:
		posi[i] = 0
	ri = n-i-1
	if nums[ri] < mini:
		mini = nums[ri]
	else:
		posi[ri] = 0
print(sum(posi))
