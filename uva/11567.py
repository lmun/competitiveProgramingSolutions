from functools import lru_cache
@lru_cache(maxsize=2048)
def auxi(nu):
	if nu < 4:
		return nu
	return 1 + (min(auxi(nu-1), auxi(nu+1)) if nu % 2 else auxi(nu//2))
try:
	while True:
		print(auxi(int(input())))
except Exception as e:
	pass
