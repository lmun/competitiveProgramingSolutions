coins = [1,5,10,25,50]
mama = 30008
dp = [[0]*mama for _ in range(5)]
dp[0][0] = 1
for i in range(5):
	for j in range(mama):
		if i > 0:
			dp[i][j] = dp[i-1][j]
		if j >= coins[i]:
			dp[i][j] += dp[i][j-coins[i]]
try:
	while True:
		tar = int(input())
		resp = sum(dp[i][tar] for i in range(5))
		resp = dp[4][tar]
		if resp == 1:
			print("There is only 1 way to produce {} cents change.".format(tar))
		else:
			print("There are {} ways to produce {} cents change.".format(resp, tar))
except Exception as e:
	pass
