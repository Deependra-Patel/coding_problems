#!/usr/bin/python3
temp=input()
a=set(list(map(int, input().split(' '))))
temp=input()
b=set(list(map(int, input().split(' '))))
for x in sorted(a.difference(b).union(b.difference(a))):
	print(x)