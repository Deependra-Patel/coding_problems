#!/usr/bin/python3
t = input()
t = int(t)
for i in range(t):
	temp = input().split(" ")
	n = int(temp[0])
	m = int(temp[1])
	ans = 0
	for x in range(n):
		ans+=(x+1)%m
	print(int(ans))

