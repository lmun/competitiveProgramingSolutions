first = True
while True:
	n = int(input())
	if n == 0:
		break
	uno = [(int(input()), i) for i in range(n)]
	dos = [int(input()) for _ in range(n)]
	resp = [0]*n
	uno.sort()
	dos.sort()
	for i in range(n):
		resp[uno[i][1]] = dos[i]
	if not first:
		print()
	first = False
	for r in resp:
		print(r)
