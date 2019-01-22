n = int(input())
nums = list(map(int, input().split()))
flechas = {}
tot = 0
for num in reversed(nums):
	if flechas.get(num, 0) > 0:
		flechas[num] = flechas[num]-1
	else:
		tot += 1
	flechas[num+1] = flechas.get(num + 1, 0) + 1
print(tot)
