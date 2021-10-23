from random import randrange
exe=320
# po = 2**exe
# def te():
# 	x=0
# 	y=po-1
# 	re = 0
# 	while x != y:
# 		x|=randrange(po)
# 		re+=1
# 	return re
ma = 100
li = list(range(ma))
la = [(1-(1/(1<<i)))**exe for i in li]
lu = [0]+[la[i]-la[i-1] for i in range(1,ma)]
print(sum(map(lambda x:x[0]*x[1], zip(li,lu))))
# print(li)
print(sum(la))
print(sum(lu))
# limi = 100000000000
# limi  = 10
# tot = 0
# for i in range(1,limi+1):
# 	tot+=te()
# 	if i%1000000==0:
# 		print(tot/i)
# print(tot/limi)
