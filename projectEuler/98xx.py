from sys import stdin
cubos=list()
pril=[0]*20
for i in range(1000000001):
	n=i*i
	p=str(n)
	if pril[len(p)]==0:
		pril[len(p)]=i
	#print(p)
	cubos.append(p)
	if n> 10**12:
		break
mmm={}
maxi=0
for line in stdin:
	stli=line.strip()
	estaw=''.join(list(sorted(list(stli))))
	#print(estaw)
	if estaw not in mmm:
		mmm[estaw]=set()
	mmm[estaw].add(stli)
for key,value in mmm.items():
	if len(value)>1:
		todo={}
		for v in value:
			for i in range(pril[len(v)],pril[len(v)+1]):
				estec=['.']*26
				nunu=[False]*10
				for j in range(len(v)):
					if nunu[int(cubos[i][j])]:
						if estec[ord(v[j])-65]!=cubos[i][j]:
							#print("nononono")
							break
					else:
						if estec[ord(v[j])-65]=='.':
							estec[ord(v[j])-65]=cubos[i][j]
							nunu[int(cubos[i][j])]=True
						elif estec[ord(v[j])-65]!=cubos[i][j]:
							break
				else:
					jach=''.join(estec)
					if jach in todo:
						print("pali",todo[jach],int(cubos[i]))
						todo[jach]=max(todo[jach],int(cubos[i]))
						if todo[jach] > maxi:
							print(todo[jach])
							maxi=todo[jach]
					else:
						todo[jach]=int(cubos[i])
print(maxi)