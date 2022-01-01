a,b=10,20

if(a<b):
    print("a is smaller.")

elif(b<a):                                         #elif means "else if"
    print("b is smaller.")

else:                                              #aka the default statement
    print("a and b are equal.")

print("") 

#This whole program is 1 if statement. It is also a control structure, meaning one statement will be true at any given time.
#The program executes the first if statement that is true and exits the if statement. It doesn't matter if 2 statements are true, the program will only execute the first one.


c=56

if c>1 and c<100:
    print("c is within range")
else:
    print("c is outside of range")

print("") 

#we can also define the range using the range () function, as such: "if c in range (1,101)"


#Q: Write a program that takes your marks as input and assigns a letter grade.
#Grading scale: >90: A, >80 but <89:B, >70 but <79:C, <70:F

grade=0

students=int(input("How many students?: "))
for i in range(students):
    grade=int(input("Enter your marks: "))
    if grade>100:
        print("Invalid grade.")
    elif grade>=90:
        print("Grade: A")
    elif grade>=80:
        print("Grade: B")
    elif grade>=70:
        print("Grade: C")
    else:
        print("Grade: F")
    print("")


#Q: Write a program that takes 5 numbers from the user and prints the sum of only the positive ones.

theSum=0

for j in range(5):
    num=int(input("Enter a number: "))
    if num>0:
        theSum+=num

print("The sum of only the positive numbers=",theSum)

print("") 

#Q: Write a loop that prints even numbers between 1 and 10.

for k in range (1,11,1):
    if k%2==0:                                 #"%" is the modulo operator and returns the remainder
        print(k,end=" ")

print("\n")

#Q: Now do the same thing using a while loop

p=1

while(p<11):
    if p%2==0:
        print(p, end=" ")
    p+=1

print("\n")

#Q: Now print odd numbers.

for l in range (1,11,1):
    if l%2==1:
        print(l,end=" ")

print("\n")

#Q: Now use a while-loop.

m=1

while(m<11):
    if m%2==0:
        print(m, end=" ")
    m+=1

print("\n")

#Q: Write a program that prints the sum of all even numbers between 1 and 10.

theSum=0

for n in range(1,11,1):
    if n%2==0:
        theSum+=n

print("The sum of all even numbers between 1 and 10:", theSum)

#Q: Write a program to check if a user-input character is an alphabet or not.

uInput=input("Enter a character or number: ")

if uInput>='A' and uInput<='z':
    print(uInput,"is an alphabet.")
else:
    print(uInput,"is not an alphabet.")
