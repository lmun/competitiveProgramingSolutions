for t in range(int(input())):
	n, m = map(int,input().split())
	res = 0
	for i in range(n-1):
		row = input().strip()
		if row[-1]=='R':
			res += 1
	row = input().strip()
	for c in row[:m-1]:
		if c == 'D':
			res+=1
	print(res)
