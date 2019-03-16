while True:
	n, m = map(int, input().split())
	if n == 0 and n == m:
		break
	dra = [int(input()) for _ in range(n)]
	kni = [int(input()) for _ in range(m)]
	dra.sort()
	kni.sort()
	k = 0
	res = 0
	for d in dra:
		while k < len(kni) and kni[k] < d:
			k += 1
		if k == len(kni):
			print("Loowater is doomed!")
			break
		else:
			res += kni[k]
			k += 1
	else:
		print(res)
