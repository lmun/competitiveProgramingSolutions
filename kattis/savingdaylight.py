from sys import stdin
def tomin(hora):
	h, m = map(int, hora.split(':'))
	return h*60 + m

def prettyprintmin(mins):
	return "{} hours {} minutes ".format(mins//60, mins%60)

for line in stdin:
	palas = line.split()
	print("{} {}".format(" ".join(palas[:3]), prettyprintmin(tomin(palas[-1]) - tomin(palas[-2]))))