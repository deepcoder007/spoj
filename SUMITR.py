n=int(raw_input())
for x in range(n):
	l=int(raw_input())
	a=list()
	for y in range(l):
		a.append( [ int(c) for c in  raw_input().split() ] )
	for y in range(l-1):
		for z in range(y+1):
			

