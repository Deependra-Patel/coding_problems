#!/usr/bin/python3
import math
ntest = int(input())
for i in range(ntest):
	temp = input()
	m, n = [float(x) for x in input().split(' ')]
	#n = float(input())
	if m>n:
		n = int(math.ceil(n/2))
	else :
		m = int(math.ceil(m/2))
	print(m*n)

