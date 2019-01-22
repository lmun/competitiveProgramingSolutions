while True:
	try:
		h, u, d, f = map(int, input().split())
		if h == 0:
			break
		h *= 100
		act = 0
		day = 0
		fac = 100
		while True:
			# print(day, act, 100*d, fac, u*fac)
			day += 1
			if fac > 0:
				act += u * fac
			fac -= f
			if act > h:
				print("success on day {}".format(day))
				break
			act -= 100 * d
			if act <= 0:
				print("failure on day {}".format(day))
				break
			
	except Exception as e:
		print(e)
		break
	else:
		pass
	finally:
		pass