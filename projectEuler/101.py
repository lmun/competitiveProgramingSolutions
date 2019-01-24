from sys import stdin
res=0
for line in stdin:
	arr=list(map(int,line.split(',')))
	#d=(x−x1)(y2−y1)−(y−y1)(x2−x1)
	d=-1*arr[0]*(arr[3]-arr[1])+arr[1]*(arr[2]-arr[0])
	e=-1*arr[2]*(arr[5]-arr[3])+arr[3]*(arr[4]-arr[2])
	f=-1*arr[4]*(arr[1]-arr[5])+arr[5]*(arr[0]-arr[4])
	#print(d*e,d*f)
	if d*e > 0 and d*f>0:
		res+=1
print(res)