import io
import os
import sys

f=open('in.txt','r')
a=list()

for x in f:
	x=x.split();
	x=[ int(y) for y in x]
	a.extend(x)

print len(a)
f.close()
f=open('out.txt','w')
f.write(str(a))
f.close()
