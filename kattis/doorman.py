while True:
	try:
		x = int(input())
		word = input().strip()
		pri = word[0]
		la = len(word)
		w = 0
		m = 0
		i = 1
		while i < la:
			sig = word[i]
			# print(i, w, m, pri, sig)
			if sig != pri:
				w += 1
				m += 1
				if i + 1 == la:
					pri = None
				else:
					pri = word[i + 1]
					i += 1
			elif pri == 'W':
				if w - m < x:
					w += 1
				else:
					break
			elif pri == 'M':
				if m - w < x:
					m += 1
				else:
					break
			i += 1
		if pri is not None:
			if pri == 'W' and w + 1 - m <= x:
				print(w + m + 1)
			elif pri == 'M' and m + 1 - w <= x:
				print(w + m + 1)
			else:
				print(w + m)
		else:
			print(w + m)



	except Exception as e:
		break
	