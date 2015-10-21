#!/usr/bin/python3
import string, random
x = ""
print(10000)
for i in range(10000):
    x += 'a'+''.join(random.choice(string.ascii_lowercase + string.ascii_uppercase + string.digits + '+'+'.') for _ in range(50)) + '@' + ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(50)) + 'z\n'
print(x);
