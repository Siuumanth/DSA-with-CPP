heights=[1,6,8,11]
bricks=5
c,d=0,0
ladders=1
for i in range(0,len(heights)-1,1):
    a,b=heights[i],heights[i+1]
    d=b-a
    if(d>0):
        if(d<=bricks):
            bricks-=d
            c=c+1
        elif(ladders>0):
            ladders-=1
            c=c+1
        else:
            break
    elif(d<=0):
        c+=1

print("number of buildingd crossed = ",c)




