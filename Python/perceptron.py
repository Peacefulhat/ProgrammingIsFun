def activation_function(inputs,weights,bias):
    sum=0
    for i in range(0,len(inputs)):
        sum=sum+inputs[i]*weights[i]

    return 1 if (sum+bias)>=0 else 0


 x1= [0,0,1,1]
 x2= [0,1,0,1]

 
