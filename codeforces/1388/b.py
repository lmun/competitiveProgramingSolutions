for t in range(int(input())):
	n = int(input())
	le = (n-1)//4+1
	wa = '9'*(n-le)+'8'*le
	print(wa)
	# print(n, wa)
	# print(''.join('{:b}'.format(int(a)) for a in wa))
