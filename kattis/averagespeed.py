# uva 10281
def tosec(x):
	h,m,s=map(int,x.split(':'))
	return 3600*h+60*m+s
v = 0
p = 0
lt = 0
while True:
	try:
		x = list(input().split())
		t = tosec(x[0])
		p += (t-lt)*v
		lt = t
		if len(x) > 1:
			v = int(x[1])
		else:
			# print(p/3600)
			print("{} {:.2f} km".format(x[0], p/3600))
	except Exception as e:
		# print(e)
		break
