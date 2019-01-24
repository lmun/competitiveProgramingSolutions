def sumdigi(n):
	return sum(int(i) for i in str(n))

canti = [0]*100
for i in range(10, 100):
	if sumdigi(i) <= 9:
		canti[i] += 1
for tt in range(3, 1001):
	nextcanti = [0]*100
	for i in range(100):
		if canti[i] > 0:
			for j in range(10-sumdigi(i)):
				nextcanti[(i%10)*10+j] += canti[i]
	canti = nextcanti

#print(sum(canti))
print(sum(nextcanti))
