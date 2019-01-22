for t in range(int(input())):
	l1 = input().strip()
	l2 = input().strip()
	s = ['.' if l1[i] == l2[i] else '*' for i in range(len(l1))]
	print(l1)
	print(l2)
	print(''.join(s))
	print()
