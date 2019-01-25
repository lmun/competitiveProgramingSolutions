for i in range(int(input())):
	mapa = {}
	nums = [int(input()) for _ in range(int(input()))]
	resp = 0
	ultimo = -1
	for j in range(len(nums)):
		este = nums[j]
		ultimo = max(mapa.get(este, -1), ultimo)
		resp = max(j - ultimo, resp)
		mapa[este] = j
	print(resp)
