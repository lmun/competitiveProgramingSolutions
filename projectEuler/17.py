def ntoword(n):
	menosdediez={
		0: "",
		1:"one",
		2:"two",
		3:"three",
		4:"four",
		5:"five",
		6:"six",
		7:"seven",
		8:"eigth",
		9:"nine",
		10:"ten",
		11:"eleven",
		12:"twelve",
		13: "thirteen",
		14: "fourteen",
		15: "fifteen",
		16: "sixteen",
		17: "seventeen",
		18: "eighteen",
		19: "nineteen",
		20: "twenty"
	}
	decenas={
		2:"twenty",
		3: "thirty",
		4: "forty",
		5: "fifty",
		6: "sixty",
		7: "seventy",
		8: "eighty",
		9: "ninety"
	}
	if n < 10:
		return menosdediez.get(n)
	if n < 21:
		return menosdediez.get(n)
	if n < 100:
		return decenas.get(n//10)+ntoword(n%10)
	if n < 1000:
		xx=ntoword(n%100)
		return menosdediez.get(n//100)+"hundred"+("and"+xx if len(xx)>0 else "")
	if n==1000:
		return "onethousand"
t=0
for i in range(1,1001):
	print(i,ntoword(i),len(ntoword(i)))
	t+=len(ntoword(i))
print(t)