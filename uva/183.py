from itertools import product
class Mat(object):
	"""docstring for Mat"""
	def __init__(self, h, w):
		super(Mat, self).__init__()
		self.h = h
		self.w = w
		self.mat = [['0']*w for _ in range(h)]
	def todstr(self):
		return "".join(("".join(m) for m in self.mat))
	def tobstraux(self, ix, iy, fx, fy):
		if fx-ix < 1 or fy-iy < 1:
			return ""
		if all(self.mat[x][y]==self.mat[ix][iy] for x, y in product(range(ix,fx), range(iy,fy))):
			return str(self.mat[ix][iy])
		else:
			mx = (ix+fx+1)//2
			my = (iy+fy+1)//2
			return "D" + self.tobstraux(ix, iy, mx, my) + self.tobstraux(ix, my, mx, fy) + self.tobstraux(mx, iy, fx, my) + self.tobstraux(mx, my, fx, fy)
	def tobstr(self):
		return self.tobstraux(0,0, h, w)
	def loadbstr(self, st):
		for i in range(len(st)):
			self.mat[i//w][i%w] = st[i]
	def loaddstr(self, st):
		stack = [(0,0,h,w)]
		for c in st:
			ix, iy, fx, fy = stack.pop()
			if c == "0" or c == "1":
				for x, y in product(range(ix,fx), range(iy,fy)):
					self.mat[x][y] = c
			else:
				mx = (ix+fx+1)//2
				my = (iy+fy+1)//2
				if fy - my > 0 and fx - mx > 0:
					stack.append((mx, my, fx, fy))
				if fx - mx > 0:
					stack.append((mx, iy, fx, my))
				if fy - my > 0:
					stack.append((ix, my, mx, fy))		
				stack.append((ix,iy,mx,my))


def print50(st):
	for y in range(0,len(st), 50):
		print(st[y:y+50])


while True:
	wi = input()
	if wi[0] == '#':
		break
	n, h, w = wi.split()
	h, w = int(h), int(w)
	otraletra = "B" if n == 'D' else "D"
	print("{}{: >4}{: >4}".format(otraletra, h, w))
	if n == 'D':
		wo = input().strip()
		ma = Mat(h, w)
		ma.loaddstr(wo)
		print50(ma.todstr())
	else:
		wo = ""
		for _ in range((h*w-1)//50 +1):
			wo += input().strip()
		ma = Mat(h, w)
		ma.loadbstr(wo)
		print50(ma.tobstr())