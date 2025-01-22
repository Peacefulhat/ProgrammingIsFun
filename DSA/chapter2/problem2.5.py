a=[1,0,1,1,0]
b=[0,1,1,1,0]
carry=0
c=[]
i=len(a)-1
print(i)
while (i>=0):
    if(a[i]==1 and b[i]==1):
        if(carry==1):
            c.append(1)
            continue
        carry=1
        c.append(0);
    elif carry==1 and a[i]==0 and b[i]==0:
        carry=1
        c.append(0)
    elif carry==1 and (a[i]==0 and b[i]==1) or(a[i]==1 and b[i]==0):
        c.append(0)
    else:
        c.append(1)
    i=i-1
print(c)
