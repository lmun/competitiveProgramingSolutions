def singlescore(card):
	letra=card[0]
	if letra=='J':
		return 11
	if letra=='Q':
		return 12
	if letra=='K':
		return 13
	if letra=='A':
		return 14
	if letra=='T':
		return 10
	return int(letra)

def strait(h):
	return any(all((singlescore(h[(i+j)%5])-1)%13==singlescore(h[(i+j+1)%5])-2 for i in range(4)) for j in range(5))

def flush(h):
	return all(h[0][-1]==h[i][-1] for i in range(5))

def simplescore(hand):
	s=0
	for h in reversed(range(5)):
		if h>1 and singlescore(hand[h])==singlescore(hand[h-2]):
			s+=singlescore(hand[h])*15**8
		if h>0 and singlescore(hand[h])==singlescore(hand[h-1]):
			s+=singlescore(hand[h])*15**6
		s+=singlescore(hand[h])*15**(h+1)
	return s

def four(hand):
	return any(all(singlescore[i+j]==singlescore[i+j+1] for i in range(3)) for j in range(2))
def repe(hand):
	ff=[0]*15
	for h in hand:
		ff[singlescore(h)]+=1
	return sorted(ff,reverse=True)[:5]

def score(hand):
	h=hand
	f=flush(hand)
	s=strait(hand)
	ss=simplescore(hand)
	rep=repe(hand)
	if f and s:
		return 15**20+singlescore(h[-1])
	if rep[0]==4:
		return 15**19+singlescore(h[-2])*100+singlescore(h[-1])+singlescore(h[0])
	if rep[0]==3 and rep[1]==2:
		return 15**18+singlescore(h[2])*1000
	if f:
		return 15**17+ss
	if s:
		return 15**16+ss
	if rep[0]==3:
		return 15**15+singlescore(h[2])*1000+ss
	if rep[0]==rep[1] and rep[1]==2:
		return 15**14+ss
	if rep[0]==2:
		return 15**13+ss
	return ss
tot=0
for _ in range(1000):
	li=input().split(' ')
	h1=sorted(li[:5],key=singlescore)
	h2=sorted(li[5:],key=singlescore)
	if score(h1) > score(h2):
		print(1)
		tot+=1
	else:
		print(2)
	#print('h1',h1)
	#print('h2',h2)
print(tot)