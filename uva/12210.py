t = 1
while True:
	b, s = map(int, input().split())
	if b == 0 and s == 0:
		break
	ba = [int(input()) for _ in range(b)]
	sa = [int(input()) for _ in range(s)]
	ba.sort()
	res = 0 if s >= b else b-s
	print("Case {}: {}".format(t, res), end='')
	if res > 0:
		print(" {}".format(ba[0]))
	else:
		print()
	t += 1