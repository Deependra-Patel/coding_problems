#!/usr/bin/python3
import sys
t=int(input())
st=sys.stdin.read()[::-1].split(' ')
ans=""
for i in st:
	ans+=t*(i+" ")
print(ans)
