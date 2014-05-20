#!/usr/bin/python3
n=int(input())
inp=input()
li=list(map(int, inp.split(' ')))
max1=-200
max2=-200
for temp in li:
	if temp>max1:
		max2=max1
		max1=temp
	elif temp>max2:
		max2=temp
print(max2)