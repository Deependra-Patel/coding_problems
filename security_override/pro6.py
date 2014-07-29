#!/usr/bin/python3
import math
a=1
b=int(input())
c=int(input())
f1=-int((-b + math.sqrt(b**2 - 4*a*c))/(2*a))
f2=-int((-b - math.sqrt(b**2 - 4*a*c))/(2*a))
if(f1>0):
	f1="+"+str(f1)
if(f2>0):
	f2="+"+str(f2)
f1, f2=str(f1), str(f2)
print("(x"+f1+")(x"+f2+")")