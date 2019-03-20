while True:
	n = int(input())
	if n == 0:
		break
	nums = [int(input()) for _ in range(n)]
	wa = list(filter(None, nums))
	if wa:
		print(" ".join(map(str, wa)))
	else:
		print(0)
