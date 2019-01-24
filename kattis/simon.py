for t in range(int(input())):
	a = input().strip()
	if a.startswith("Simon says "):
		print(a[11:])