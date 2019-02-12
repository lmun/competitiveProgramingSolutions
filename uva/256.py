def isquirk(n, mo):
	ab = n%mo + n//mo
	return ab*ab==n


resp = [[0]]
for j in range(1,5):
	mo = 10**j
	resp.append(['{{:0>{}}}'.format(2*j).format(i*i) for i in range(10**j) if isquirk(i*i,mo)])
while True:
	try:
		n = int(input())
		print('\n'.join(resp[n//2]))
	except Exception as e:
		#print(e)
		break
