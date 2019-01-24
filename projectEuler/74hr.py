m = 1000001
nu = [-1]*3000000
fac = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
ceros = [145, 40585, 169, 363601, 1454, 871, 45361, 872, 45362]
nu[1] = 1
nu[0] = 2
nu[2] = 1
nu[145] = 1
nu[40585] = 1
nu[169] = 3
nu[363601] = 3
nu[1454] = 3
nu[871] = 2
nu[45361] = 2
nu[872] = 2
nu[45362] = 2


def facdigi(n):
    r = 0
    for c in str(n):
        r += fac[int(c)]
    return r


def largo(n):
    if nu[n] >= 0:
        return nu[n]
    t = facdigi(n)
    nu[n] = largo(t)+1
    return nu[n]


for _ in range(int(input)):
    x, y = map(int, input.split())
    tengo = False
    for i in range(x):
        tla = largo(i)
        if tla == y:
            print(i, end="")
            tengo = True
    print("" if tengo else "-1")

print(res)

# print(largo(69))
