a = [4,5,7]
b = [1,2,3]
c = []

a1 = 0
b1 = 0
n = 3

for i in range (100):
    if(a[a1]>b[b1]):
        c.append(b[b1])
        b1+=1
    else:
        c.append(a[a1])
        a1+=1
    if(b1==n):
        for i in range(a1,n):
            c.append(a[i])
        break

    elif(a1==n):
        for i in range(b1,n):
            c.append(b[i])
        break

    if(a1==n and b1==n):
        break

print(c)