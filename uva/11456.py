for t in range(int(input())):
	le = int(input())
	if le == 0:
		print(0)
		continue
	nums = [int(input()) for _ in range(le)]
	dec = [0]*le
	cre = [0]*le
	male = [0]*le
	lis = []
	lds = []
	for i in reversed(range(le)):
		# print(lis)
		if not lis:
			lis.append(nums[i])
			cre[i] = 1
		else:
			if nums[i] < lis[-1]:
				lis.append(nums[i])
				cre[i] = len(lis)
			else:
				lo, hi = 0, len(lis)-1
				while hi>lo:
					mid = (hi+lo)//2
					if lis[mid] > nums[i]:
						lo = mid+1
					else:
						hi = mid
				# print(lis[lo], nums[i])
				if lis[lo] < nums[i]:
					lis[lo] = nums[i]
				cre[i] = lo+1
		# print(i, lds)
		if not lds:
			lds.append(nums[i])
			dec[i] = 1
		else:
			if nums[i] > lds[-1]:
				lds.append(nums[i])
				dec[i] = len(lds)
			else:
				lo, hi = 0, len(lds)-1
				while hi> lo:
					mid = (hi+lo)//2
					if lds[mid]< nums[i]:
						lo = mid+1
					else:
						hi = mid
				# print(lds[lo], nums[i])
				if lds[lo] > nums[i]:
					lds[lo] = nums[i]
				dec[i] = lo + 1
	print(max(x+y-1 for x, y in zip(dec, cre)))
