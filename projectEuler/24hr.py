def factorial(fa):
	if fa<=1:
		return 1
	else:
		return fa*factorial(fa-1)

def getPermu(num):
	letras=list("abcdefghij")
	res=""
	escritas=0
	objetivo=len(letras)
	for _ in range(len(letras)):
		valact=factorial(objetivo-1)
		este=num//valact
		num%=valact
		otro=0
		print(este)
		for i in range(len(letras)):
			if letras[i]!='.':
				if otro==este:
					res+=letras[i]
					letras[i]='.'
				otro+=1
			else:
				continue
		objetivo-=1
	return res

for _ in range(int(input())):
	s = int(input())
	print(getPermu(s-1))