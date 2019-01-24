r = [0, 1, 1, 2, 4]
g = [0, 0, 1, 1, 2]
b = [0, 0, 0, 1, 1]
n = [1, 1, 2, 4, 8]

for i in range(55):
    n.append(n[-1]+b[-1]+g[-1]+r[-1])
    r.append(n[-2])
    g.append(n[-3])
    b.append(n[-4])

# print(i, r[i]-1, g[i]-1, b[i]-1, r[i] + g[i] + b[i]-3)
print(n[50])
