arr=[1,7,3,8,5,9]
print(arr)
arr2=[]
det=0
for i in range(0,len(arr)):
    arr2.append(arr[i])
for i in range(0,len(arr)):
    for j in range(i+1,len(arr)):
        if(arr[j]>arr[i]):
            if j==len(arr):
                j=j-1
            for k in range(j+1,len(arr)):
                if arr[k]>arr[j]:
                    arr[i]=arr[k]
                    det=1
                    break
        if det==1:
            break
        
    if arr[i]==arr2[i]:
        arr[i]=-1
    
print(arr)
