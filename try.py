def determinant_3x3(m):
    return (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
            m[1][0] * (m[0][1] * m[2][2] - m[0][2] * m[2][1]) +
            m[2][0] * (m[0][1] * m[1][2] - m[0][2] * m[1][1]))


def subtract(a, b):
    return (a[0] - b[0],
            a[1] - b[1],
            a[2] - b[2])



ntest=int(input())
for i in range(ntest):
    a=list(map(int, input().split(' ')))
    b=list(map(int, input().split(' ')))
    c=list(map(int, input().split(' ')))
    d=list(map(int, input().split(' ')))
    if(abs(determinant_3x3((subtract(a, b),subtract(b, c),subtract(c, d),))) / 6.0==0):
        print("YES")
    else :
        print("NO")
