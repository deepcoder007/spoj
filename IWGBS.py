

n=int(raw_input())
out=0
for i in range(n+1):
    if (n-i+1)>=(i) :    # if numerator greater then denominator
        t1= reduce( lambda x,y : x*y , range(1,n-i+1) )
        t2= 1
        if len(range(1,i))>0 :
            t2=reduce(lambda x,y : x*y , range(1,i) )
        if len(range(1,n-2*i+1))>0:
            t2*=reduce(lambda x,y : x*y , range(1,n-2*i+1) )
        out+= (t1/t2)

print out
