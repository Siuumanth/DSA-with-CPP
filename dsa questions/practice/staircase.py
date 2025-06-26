def fact(n):
    if(n==0 or n==1):
        return 1
    else:
        return n*fact(n-1)
def permutation(n1,n2):
    return fact(n1+n2)/(fact(n1)*fact(n2))  

step=int(input("enter number of steps "))
ways=0
n2=0
sum=0
n1=step
while True:
    if((n2*2)>step or n1<0):
        break
    ways=ways+permutation(n1,n2)
    n1=n1-2
    n2=n2+1
    sum=n1*1 + n2*2
    

print("number of ways is ",ways)
    

    
