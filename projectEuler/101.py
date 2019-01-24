import numpy as np
res = list()
for i in range(1, 20):
    a = 0
    for j in range(11):
        a += (-1)**j*i**j
    # print(a)
    res.append(a)
    # res.append(i*i*i)
resultado = 0
for t in range(1, 11):
    ma = list()
    for i in range(1, t+1):
        wa = list()
        for j in range(0, t):
            wa.append(i**j)
            # print(i**j,end=" ")
        # print(wa)
        ma.append(wa)
    # print('-'*50)
    # print(ma)
    tata = np.linalg.inv(ma).dot(res[:t])
    # print(np.linalg.inv(ma).dot(res[:t]))
    # print(res[:t])
    i = t+1
    yy = list()
    for j in range(len(tata)):
        yy.append(i**j)
    # print(tata.dot(yy))
    resultado += tata.dot(yy)
print(resultado)
