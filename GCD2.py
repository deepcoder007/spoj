

def gcd2(a,b):
	if a<b:
		return gcd2(b,a)
	elif b==0 :
		return a
	else:
		return gcd2(b,a%b)


t=int(input())
for x in range(t):
	a,b=input().split()
	a=int(a)
	b=int(b)
	print(gcd2(a,b))
