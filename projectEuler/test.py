for uuu in range(50):
	a=input()
	b=[ list(map(int,list(input()))) for _ in range(9)]
	ss=[[set(range(1,10)) for _ in range(9)] for _ in range(9)]
	for i in range(9):
		for j in range(9):
			if b[i][j]!=0:
				ss[i][j]=set()
	if uuu!=6:
		#continue
		pass
	cambio=True
	lim=1
	while True:
		if not cambio:
			lim+=1
		if lim > 30:
			break
		cambio=False
		for i in range(9):
			for j in range(9):
				pos=ss[i][j]
				if b[i][j]==0:
					for s in range(9):
						pos.discard(b[i][s])	
						pos.discard(b[s][j])
					for x in range(3):
						for y in range(3):
							pos.discard(b[(i//3)*3+x][(j//3)*3+y])
					ss[i][j]=pos
					if len(pos)>0 and len(pos)==1:
						b[i][j]=pos.pop()
						#print("-",i,j,b[i][j])
						for x in range(9):
							ss[x][j].discard(b[i][j])
							ss[i][x].discard(b[i][j])
						for x in range(3):
							for y in range(3):
								ss[(i//3)*3+x][(j//3)*3+y].discard(b[i][j])
						cambio=True
					if len(ss[i][j])>2:
						for x in range(9):
							if x != j:
								waa=ss[i][j]&ss[i][x]
								if len(waa)==2 and sum(len(waa&ss[i][y]) for y in range(9))==4:
									#print("waa",i,j,waa,ss[i][j])
									pass
					if len(ss[i][j])>2:
						for x in range(9):
							if x != i:
								waa=ss[i][j]&ss[x][j]
								if len(waa)==2 and sum(len(waa&ss[y][j]) for y in range(9))==4:
									ss[i][j]=waa
									print("waa",i,j,waa,ss[i][j])
					"""if len(ss[i][j])==2:
						for x in range(9):
							for y in range(9):
								if x!=i and y!=j and len(ss[x][y])==2 and len(ss[i][y])==2 and len(ss[x][j])==2 and len(ss[i][j]&ss[x][y]&ss[i][y]&ss[x][j])>0:
									print(i,j,ss[i][j],ss[x][y],x,y)"""
					for p in pos:
						aa=0
						la=10
						for xx in range(9):
							if p in ss[i][xx]:
								aa+=1
								if xx!=j:
									la=xx
						if aa==1:
							#print(i,j,ss[i][j])
							b[i][j]=p
							#print("+",i,j,p)
							ss[i][j]=set()
							for x in range(9):
								ss[x][j].discard(b[i][j])
								ss[i][x].discard(b[i][j])
							for x in range(3):
								for y in range(3):
									ss[(i//3)*3+x][(j//3)*3+y].discard(b[i][j])
							cambio=True
							break
						bb=0
						lb=10
						for xx in range(9):
							if p in ss[xx][j]:
								bb+=1
								if xx!=i:
									lb=xx
						if bb==1:
							#print(i,j,ss[i][j])
							b[i][j]=p
							for x in range(9):
								ss[x][j].discard(b[i][j])
								ss[i][x].discard(b[i][j])
							for x in range(3):
								for y in range(3):
									ss[(i//3)*3+x][(j//3)*3+y].discard(b[i][j])
							#print("*",i,j,p)
							ss[i][j]=set()
							cambio=True
							break
						if bb==2 and aa > 2:
							for x in range(9):
								if x!=j and p in ss[i][x] and p in ss[lb][x] and sum(1 if p in ss[kk][x] else 0 for kk in range(9))==2:
									#print(i,j,lb,x,p,"o")
									for up in range(9):
										if up!=j and up!=x and p in ss[i][up] and p==1:
											pass
											#ss[i][up].discard(p)
											"""print('lim',lim)
											print(i,j,ss[i][j])
											print(lb,x,ss[lb][x])
											print(lb,j,ss[lb][j])
											print(i,x,ss[i][x])
											print(i,up,p,'..',ss[i][up])
											for pp in range(9):
												#print(pp,'-'.join(map(str,ss[pp])))
												pass"""
						elif aa==2 and bb >2:
							for x in range(9):
								if x!=i and p in ss[x][j] and p in ss[x][la] and sum(1 if p in ss[x][kk] else 0 for kk in range(9))==2:
									#print(i,j,x,la,p,"u")
									for up in range(9):
										if up!=i and up!=x:
											ss[up][j].discard(p)
						cc=0
						cca=0
						ccb=0
						for x in range(3):
							for y in range(3):
								if p in ss[(i//3)*3+x][(j//3)*3+y]:
									cc+=1
							if p in ss[(i//3)*3+x][j]:
								ccb+=1
							if p in ss[i][(j//3)*3+x]:
								cca+=1
						if cc==1:
							b[i][j]=p
							ss[i][j]=set()
							for x in range(9):
								ss[x][j].discard(b[i][j])
								ss[i][x].discard(b[i][j])
							for x in range(3):
								for y in range(3):
									ss[(i//3)*3+x][(j//3)*3+y].discard(b[i][j])
							cambio=True
							break
						#print(aa)
						if cca==aa and cc>aa:
							#print(i,j,p,aa,bb,cc)
							for x in range(3):
								for y in range(3):
									fa,fb=(i//3)*3+x,(j//3)*3+y
									if fa!=i and p in ss[fa][fb]:
										ss[fa][fb].discard(p)
						if ccb==bb and cc>bb:
							#print(i,j,p,aa,bb,cc)
							for x in range(3):
								for y in range(3):
									fa,fb=(i//3)*3+x,(j//3)*3+y
									if fb!=j and p in ss[fa][fb]:
										ss[fa][fb].discard(p)
						if cca==cc and aa>cc:
							for x in range(9):
								if x//3!=j//3 and p in ss[i][x]:
									ss[i][x].discard(p)
									#print(i,x,p,"nono")
						if ccb==cc and bb>cc:
							for x in range(9):
								if x//3!=i//3 and p in ss[x][j]:
									ss[x][j].discard(p)
									#print(x,j,p,"ok")
					if len(pos)==2:
						for ttt in range(9):
							if ttt!=i and len(ss[ttt][j])==2 and len(ss[ttt][j]&ss[i][j])==2:
								for wa in range(9):
									if wa!=i and wa!=ttt:
										for po in pos:
											ss[wa][j].discard(po)
							if ttt!=j and len(ss[i][ttt])==2 and len(ss[i][ttt]&ss[i][j])==2:
								for wa in range(9):
									if wa!=j and wa!=ttt:
										for po in pos:
											ss[i][wa].discard(po)

			#print(b[i][j],end="")
	for pp in range(1):
		print(''.join(list(map(str,b[pp]))))
		#print(ss[pp])
		#print('-'.join(map(str,ss[pp])))
	for pp in range(9):
		#print(''.join(list(map(str,b[pp]))))
		#print(b[pp])
		pass
	print("---")