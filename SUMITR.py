n=int(input())
for x in range(n):
	l=int(input())
	a=list()
	for y in range(l):
		a.append(map(int,input().split()))
	l-=2
	while l>=0:
		z=0
		while z<=l:
			a[l][z]+=max(a[l+1][z],a[l+1][z+1])
			z+=1
		l-=1
	print(a[0][0])
			

