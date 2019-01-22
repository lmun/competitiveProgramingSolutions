fact = [1] * 12
for i in range(1, 12):
	fact[i] = (fact[i-1] * i) % 10
for i in range(int(input())):
	print(fact[int(input())])
