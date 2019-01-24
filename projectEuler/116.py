r = [1, 1, 2, 3]
g = [1, 1, 1, 2]
b = [1, 1, 1, 1]
for i in range(4, 55):
    r.append(r[-1]+r[-2])
    g.append(g[-1]+g[-3])
    b.append(b[-1]+b[-4])

print(i, r[i]-1, g[i]-1, b[i]-1, r[i] + g[i] + b[i]-3)
