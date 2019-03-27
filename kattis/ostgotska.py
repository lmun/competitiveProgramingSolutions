a = list(input().split())
if sum(1 if x.find("ae")>=0 else 0 for x in a)*10 >= 4*len(a):
	print("dae ae ju traeligt va")
else:
	print("haer talar vi rikssvenska")
