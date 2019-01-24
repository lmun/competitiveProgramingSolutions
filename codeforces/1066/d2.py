n, m, k = map(int,input().split())
nums = list(map(int, input().split()))
tot = [0]*n
maxi = [0]*n
for i in reversed(range(n)):
	su = 0
	co = 0
	for j in range(i, n):
		if su + nums[j] > k:
			break
		su += nums[j]
		co += 1
	tot[i] = co
for i in range(n):
	caj = i
	for _ in range(m):
		if caj >= n:
			break
		maxi[i] += tot[caj]
		caj += tot[caj]
print(max(maxi))