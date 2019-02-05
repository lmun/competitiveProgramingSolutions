word = input().strip()
p1 = 0
p2 = 1 if word[0] == 'U' else 0
p3 = 0
if word[0] == 'D':
	if word[1] == 'U':
		p1 = 1
	else:
		p1 = -1
else:
	if word[1]=='D':
		p2 = 1
	else:
		p2 = -1

for i in range(1, len(word)):
	if word[i] == 'D':
		p1 += 2
		if word[i-1] == 'U':
			p3 += 1
	else:
		p2 += 2
		if word[i-1] == 'D':
			p3 += 1
print(p1, p2, p3, sep='\n')
