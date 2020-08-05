for t in range(int(input())):
	n = int(input())
	arr = [int(x) for x in input().split()]
	arr.sort()
	for i in range(len(arr)-1):
		if arr[i+1] - arr[i] >1:
			print("NO")
			break
	else:
		print("YES")
