
while True:
    list=[]
    n= int(input())
    if n==-1:
        break
    else:
        for i in range(1,n):
            if n%i ==0:
                list.append(i)

        if sum(list)==n:
            print(n," = ", " + ".join(str(j) for j in list), sep="")
        else :
            print(n, "is NOT perfect.")

 