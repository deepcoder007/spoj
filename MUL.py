import io
import os
import sys


if __name__=='__main__':
	n=int(input())
	for x in range(n):   # for all the numbers
		a,b=map(int,input().split())
		print(a*b)

