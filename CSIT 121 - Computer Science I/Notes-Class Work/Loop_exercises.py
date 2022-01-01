#example of nested while loops

i=0
j=0

while(i<3):
    while(j<3):
        print("i="+str(i),"j="+str(j))
        j+=1
    i+=1
    j=0

print("\n")


#print the following nested for-loop output using a nested while-loop

for x in range(1,6):
    
    for y in range(0,x):
        print(x,end="")
        
    print()

print("\n")

#using while-loop

a=1
b=0

while(a<6):

    while(b<a):
        print(a,end="")
        b+=1

    b=0
    a+=1

    print()

print("\n")


#print the following nested for-loop output using a nested while-loop

for c in range(1,6):

    for d in range(1,c+1):
      print(d,end="")

    print()


print("\n")

#using while-loop

p=1
q=1

while(p<6):

  while(q<p+1):
    print(q,end="")
    q+=1
  
  q=1
  p+=1

  print()
