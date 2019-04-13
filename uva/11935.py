try:
	while True:
		fuel, consumption, leaks, position, res = 0, 0, 0, 0, 0
		while True:
			vals = input().split()
			di = int(vals[0]) - position
			fuel -= (consumption+leaks)*di
			position = int(vals[0])
			if vals[1] == "Fuel":
				consumption = int(vals[-1])/100
			elif vals[1] == "Leak":
				leaks += 1
			elif vals[1] == "Mechanic":
				leaks = 0
			elif vals[1] == "Goal":
				print("{:.3f}".format(-min(res,fuel)))
				break
			elif vals[1] == "Gas":
				res = min(fuel, res)
				fuel = 0
except Exception as e:
	pass
