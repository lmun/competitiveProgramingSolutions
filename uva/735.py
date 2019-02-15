from itertools import product, combinations_with_replacement

posi = set()
posi.add(50)
for i in range(21):
	posi.add(i)
	posi.add(i*2)
	posi.add(i*3)
comb = combinations_with_replacement(posi, 3)
perm = product(posi, repeat=3)
combi = [0]*1000
permu = [0]*1000
sepa = '*'*70

for c in comb:
	combi[sum(c)] += 1
for p in perm:
	permu[sum(p)] += 1

while True:
	n = int(input())
	if n <= 0:
		break
	if combi[n] == 0:
		print("THE SCORE OF {} CANNOT BE MADE WITH THREE DARTS.".format(n))
	else:
		print("NUMBER OF COMBINATIONS THAT SCORES {} IS {}.".format(n, combi[n]))
		print("NUMBER OF PERMUTATIONS THAT SCORES {} IS {}.".format(n, permu[n]))
	print(sepa)
print("END OF OUTPUT")
