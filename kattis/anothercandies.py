for _ in range(int(input())):
	input()
	n = int(input())
	print('YES' if sum(int(input()) for i in range(n)) % n == 0 else 'NO')
