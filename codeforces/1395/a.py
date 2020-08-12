for t in range(int(input())):
	nu = list(map(int, input().split()))
	re = sum(n%2 for n in nu)
	if re < 2:
		print("YES")
	elif nu[0]> 0 and nu[1]>0 and nu[2]>0 and re > 2:
		print("YES")
	else:
		print("NO")

