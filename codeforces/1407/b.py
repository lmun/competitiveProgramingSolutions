def gcd(a,b):
	if b == 0:
		return a
	return gcd(b,a%b)

for t in range(int(input())):
	n = int(input())
	nums = list(map(int, input().split()))
	used = [False]*n
	res = []
	mai = 0
	for i in range(n):
		if nums[i]>nums[mai]:
			mai = i
	used[mai] = True
	res.append(nums[mai])
	cai =1
	lg = res[0]
	while True:
		cai = -1
		mg = 0
		for i in range(n):
			if not used[i]:
				gg= gcd(lg,nums[i])
				if cai<0 or gg>mg or (gg==mg and nums[i]>nums[cai]):
					cai = i
					mg = gg
		if cai<0:
			break
		lg = mg
		used[cai] = True
		res.append(nums[cai])
	print(*res)