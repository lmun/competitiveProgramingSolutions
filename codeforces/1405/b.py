for t in range(int(input())):
	n = int(input())
	nums = list(map(int, input().split()))
	al = 0
	for nu in nums:
		if nu >= 0:
			al+=nu
		else:
			al = max(nu+al,0)
	print(al)
