n, t = map(int, input().split())
dis = []
vel = []
epsilon = 0.00000001
for _ in range(n):
    a, b = map(float, input().split())
    dis.append(a)
    vel.append(b)
mini = epsilon - min(vel)
maxi = mini
aa = 1
while True:
    tt = sum(dis[i] / (vel[i] + maxi) for i in range(n))
    maxi += aa
    aa *= 2
    if tt < t:
        break
while maxi - mini > epsilon:
    midi = (maxi + mini) / 2
    if sum(dis[i] / (vel[i] + midi) for i in range(n)) > t:
        mini = midi
    else:
        maxi = midi
print(maxi)
