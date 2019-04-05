def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

x, y = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
a = gcd(x, y)
if a == 1:
	print("Yes")
else:
	px, py = x//a, y//a
	if x1 <= px <= x2 and y1 <=py<=y2: # el primero esta cortado
		if x1 <= x-px <= x2 and y1 <=y-py<=y2: # el ultimo esta cortado
			print("Yes")
		else:
			wa = min(x2//px+1, y2//py+1)
			print("No")
			print(px*wa, py*wa)
	else:
		print("No")
		print(px, py)
