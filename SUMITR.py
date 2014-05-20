n=int(raw_input())
for x in range(n):
	l=int(raw_input())
	a=list()
	for y in range(l):
		a.append([int(c) for c in raw_input().split()])
	y=l-2 
	while y>=0:
		z=0
		while z<=y:
			a[y][z]+=max(a[y+1][z],a[y+1][z+1])
			z+=1
		y-=1
	print a[0][0]
			

