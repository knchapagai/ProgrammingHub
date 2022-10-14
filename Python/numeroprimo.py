n=int(input("Digite o numero: "))
t=2
s=1
while t<=n:
    r=n%t
    while s<=t:
        q=s*t
    if q==n or (r==0 and t!=n):
        primo= False
    else:
        primo= True
    t+=1
    s+=1

print("É primo?", primo)
