n, x = map(int, input().split())
nums = list(map(int, input().split()))
minis = [10**8]*n
for t in range(x):
	for j in range(t, n):
		minis[j] = min(minis[j], nums[j-t])
print(sum(nums[j] - minis[j] for j in range(n)))
print(minis)
