#!/usr/bin/python3
n=int(input())
dic={}
for i in range(n):
	stri=input().split(' ');
	#print(stri)
	x=float(stri[1])
	y=float(stri[2])
	z=float(stri[3])
	dic[stri[0]]=(x+y+z)/3;
print("%.2f" %dic[input()])