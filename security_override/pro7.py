#!/usr/bin/python3
import math
x=int(input())
total=0
def prime_fac(y):
	for i in range(2,math.ceil(math.sqrt(y))+1):
		if y%i==0:
			return i
	return -1;
temp=x
for i in range(2, x):
	fac = prime_fac(temp)
	if fac==-1:
		total+=temp
		break
	else :
		temp = temp/fac
		total+=fac
print(int(total))
