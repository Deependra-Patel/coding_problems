#!/usr/bin/python3
def clean(str):
	only_zeros = True
	ans = ""
	for char in str:
		if not (char=='0' and only_zeros):
			ans+=char
			only_zeros = False
	return ans

ntest = int(input())
for i in range(ntest):
	c = []
	p = []
	cases = int(input())
	for j in range(cases):
		temp = input().split(" ")
		c.append(temp[0])
		p.append(temp[1])

	string = list(input())
	checker = list("0"*len(string))
	for k in range(len(c)):
		for char_index in range(int(len(string))):
			if checker[char_index]=="0" and string[char_index]==c[k]:
				checker[char_index]="1"
				string[char_index] = p[k]
		#string = string.replace(c[k], p[k])
		#print(str(k)+" string"+string)
	#print(string)
	ans = clean(string)
	ans = clean(ans[::-1])[::-1]
	if ans[-1]=='.':
		print(ans[0:-1])
	else :
		print(ans)
	
