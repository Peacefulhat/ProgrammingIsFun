#day6 project inversion
#inversion A[0:n-1], i and j, i<j, A[i]>A[j], then pair of (i,j) is  called inversion

def inversion(A):
    i=0
    j=i+1

    B=[]
    while(i<len(A)-1):
        if(A[i]>A[j]):
            B.append(i)
            B.append(j)
            j+=1
        i+=1

    for i in range(0,len(B)-1,2):
        print(B[i],B[i+1])


A=[2,3,8,6]
inversion(A)
