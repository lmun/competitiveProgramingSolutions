for t in range(int(input())):
	n = int(input())
	nums = [int(x) for x in input().split()]
	res = []
	for i in range(n//4):
		# print(res)
		a, b = nums[4*i]+nums[4*i+2],nums[4*i+1]+nums[4*i+3]
		if a==b:
			res.extend(nums[4*i:4*i+4])
		elif a==0 or b==0:
			res.append(0)
			res.append(0)
		elif a==2 or b==2:
			res.append(1)
			res.append(1)
	if n%4:
		if nums[-1]==nums[-2]:
			res.append(nums[-2])
			res.append(nums[-1])
		else:
			res.append(0)
	print(len(res))
	print(*res)