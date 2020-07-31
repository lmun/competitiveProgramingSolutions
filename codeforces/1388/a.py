for t in range(int(input())):
	n = int(input())
	if n >= 31:
		print("YES")
		d = n-30
		if d == 6 or d==10 or d==14:
			print(6,10,15,d-1)
		else:
			print(6,10,14,d)
	else:
		print("NO")