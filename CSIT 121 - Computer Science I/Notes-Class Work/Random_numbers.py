import random

#Q: Generate a random number between 1 and 10, and ask the user to guess a number between 1 and 10. Give the user 3 tries to guess, and print the appropriate message based on the user's guess.

num=random.randint(1,10)

x=3

print("The computer has generated a random number between 1 and 10. See if you can guess it.\n")

#print("Ans:", num,"\n")                     #check answer

while(x>0):
    uNum=int(input("Guess a number between 1 and 10: "))
    
    if uNum==num:
        print("Congrats, you got it!!\n")
        break
    else:
        if x>2:
            print("Sorry, please try again.")
            x-=1
            print("You have",x,"tries left.\n")
        elif x>1:
            print("Sorry, please try again.")
            x-=1
            print("You have 1 try left.\n")
        else:
            print("Incorrect. You have no more tries left.\n")
            x-=1

print("Thanks for playing!")

print("\n")

#Q: Write a program that accepts the lengths of three sides of a triangle as inputs, and outputs whether or not the triangle is a right triangle.

AB=int(input("Side AB: "))
BC=int(input("Side BC: "))
CA=int(input("Side CA: "))

if AB^2+BC^2==CA^2 or \
   BC^2+CA^2==AB^2 or \
   CA^2+AB^2==BC^2:
    print("This is a right triangle.")
else:
    print("This is not a right triangle.")

print("\n")

#Q: Write a program that dynamically generates and prints the following output

i=97

while(i<123):
    if i%2==1:
        print(chr(i),end=" ")
    elif i%2==0:
        print(chr(i-32),end=" ")
    i+=1

print("\n")

#without using an if-statement

j=97

while(j<123):
    print(chr(j),chr(j-31),end=" ")
    j+=2

print("\n")

#Q: Let the user input a string of characters, alphabets, numbers, and special characters. Your program should print the number of non-alphabets entered by the user.

string=input("Enter a string of characters, alphabets, numbers, and special characters: ")

k=0
theSum=0

while (k<len(string)):
    if ord(string[k])<65 or\
       ord(string[k])>90 and ord(string[k])<97 or\
       ord(string[k])>122:
        theSum+=1
    k+=1

print("The number of non-alphabets in your input is:",theSum)
        
