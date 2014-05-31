import io
import os
import math

while True:
	a=raw_input().split()
	a,b=map(int,a)
	if a==0 and b==0:
		break
	if b==0:
		print 1
	else:
		print a**b
