def toledstr(num):
	li = ['|' if num & (1<<i) else ' ' for i in reversed(range(7))]
	for i in range(0,8,3):
		if li[i] == '|':
			li[i] = '_'
	return ' {0} \n{5}{6}{1}\n{4}{3}{2}'.format(*li)

repes = [0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011]
#print('\n'.join(map(toledstr, repes)))
#print(repes)
while True:
	n = int(input())
	if n == 0:
		break
	seq = [sum(y<<z for y,z in zip(map(lambda x:1 if x =='Y' else 0, input().strip()), reversed(range(7)))) for _ in range(n)]
	posi = False
	for i in range(n-1, 10):
		blocked = 0
		for a,b in zip(reversed(range(i+1)), seq):
			if blocked & b:
				break
			eb = repes[a]^b
			if eb|repes[a] != repes[a]:
				break
			blocked |= eb
		else:
			posi = True
			break
	print("MATCH" if posi else "MISMATCH")
