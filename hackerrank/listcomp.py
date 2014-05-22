#!/usr/bin/python3
x=int(input())
y=int(input())
z=int(input())
n=int(input())
vals=[]
for x1 in range(x+1):
	for y1 in range(y+1):
		for z1 in range(z+1):
			vals.append([x1, y1, z1]);	
print ([tax for tax in  vals if tax[0]+tax[1]+tax[2]!=n])
