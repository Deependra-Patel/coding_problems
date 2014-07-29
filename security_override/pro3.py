#!/usr/bin/python3
from itertools import permutations
f=open("dictionary.txt",'r')
full=[]
for line in f:
	#print(line.split(","))
	full = [x.strip() for x in line.split(",")]

def return_ans(a):
	#a = str(a)
	listp = [''.join(p) for p in permutations(a)]
	for p in listp:
		if p in full:
			return p
all_3=(input()).strip()
arr=all_3.split(", ")
x,y,z =str(arr[0]), str(arr[1]), str(arr[2])
print(return_ans(str(x))+", "+return_ans(str(y))+", "+return_ans(str(z)))
