#!/usr/bin/python3
a=input()
b=input()
count=0
for i in range(len(a)-len(b)+1):
	if(a[i:i+len(b)]==b):
		count+=1
print(count)
