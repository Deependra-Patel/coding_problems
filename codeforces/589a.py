#!/usr/bin/python3
def processE(email):
    email = email.lower()
    domain = email.split('@')[1]
    id = email.split('@')[0]
   # print(domain)
    if(domain == "bmail.com"):
        id = id.replace('.','')
        index = id.find('+')
        if(index != -1):
            id = id[0:index]
    return id+'@'+domain
    
n = int(input())
mymap = {}
count = {}
for i in range(n):
    email = input()
    processed = processE(email)
    #print(processed)
    if(processed in mymap):
        mymap[processed] += email+" "
    else :
        mymap[processed] = email+" ";
    if(processed in count):
        count[processed] += 1
    else :
        count[processed] = 1        

print(len(mymap))
ans = ""
for key, value in mymap.items():
    ans += str(count[key])+" "+value+"\n"
print(ans);
        
        
