#write a program that prints a user-input name 3 times

#using for-loop

name=input("Enter your name: ")

for x1 in range (3):
    print(name)

print("")

#using while-loop
    
y1=0

while (y1<3):
    print(name)
    y1+=1

print("")

#write a program that calculates a factorial of a user-input number

#using for-loop

num1=int(input("Enter a positive integer: "))
fact=1

for x2 in range(num1,0,-1):
    fact=fact*x2

print(str(num1)+"!= "+str(fact)) 

print("")

#using while-loop

y2=num1
fact=1

while(y2>0):
    fact=fact*y2
    y2-=1

print(str(num1)+"!= "+str(fact))

print("")

#print the first 128 values from the ASCII table

#using for-loop

for x3 in range (128):
    print(chr(x3), end=" ")

print("")

#using while-loop

y3=0

while(y3<128):
    print(chr(y3), end=" ")
    y3+=1

print("\n")

#write a program that takes a name as input and prints it in ASCII

print("This program takes your name as input and prints it in ASCII")

uName=input("Enter your name: ")

print("")

#using for-loop

for x4 in uName:
    print(ord(x4),end=" ") 

print("")

#using while-loop

y4=0

while(y4<len(uName)):
    print(ord(uName[y4]),end=" ")
    y4+=1

print("\n")

#write a program that takes an input from the user and prints each character from the input one space apart

uName=input("Enter a name: ")

y5=0

while(y5<len(uName)):
    print(uName[y5],end=" ")
    y5+=1

print("\n")

#write a program that prints every other number from 1 to 10

#using for-loop

for x6 in range (0,10,2):
    print(x6,end=" ")

print("\n")
      
#using while-loop

y6=0

while(y6<10):
    print(y6,end=" ")
    y6+=2
