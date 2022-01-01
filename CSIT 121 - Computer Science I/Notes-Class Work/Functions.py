#Write a program that can take two or three inputs from the user and returns the sum.

def add(a,b,c=5):
  return a+b+c

num1=int(input("Enter a number: "))
num2=int(input("Enter a number: "))

print(add(a=num1,b=num2),"\n")

#Write a program that has four functions (add(), sub(), mul(), div()) which take two inputs each. Take two numbers and an operator as input from user. Based on the operator call the specific function and print the result. Also, check for divide by zero error in the divide function.

def add(a,b):
  return a+b

def sub(a,b):
  return a-b

def mul(a,b):
  return a*b

def div(a,b):
  if b!=0:
    return a/b

  return "undefined"      #we don't need else because the return acts as a break

num1=int(input("Enter a number: "))
num2=int(input("Enter a number: "))
sign=input("Enter an operator: ")

if sign=='+':
  print(num1,sign,num2,"=",add(a=num1,b=num2),"\n")
elif sign=='-':
  print(num1,sign,num2,"=",sub(a=num1,b=num2),"\n")
elif sign=='*':
  print(num1,sign,num2,"=",mul(a=num1,b=num2),"\n")
elif sign=='/':
  print(num1,sign,num2,"=",div(a=num1,b=num2),"\n")
else:
  print("Invalid operator.")

#Create a list of numbers using user inputs. As soon as the user enters a 0 you should stop taking more numbers as input. Pass this list to a function that finds the smallest number in the list. Return the smallest number back to your driver and print it.
def smallest(aList):
  small=aList[0]
  
  for eachNum in aList:
    if small>eachNum:
      small=eachNum

  return small

uList=[]

while(True):
  uNum=int(input("Enter a number: "))

  if uNum!=0:
    uList.append(uNum)

  else:
    break

if uList==[]:
  print("Please enter at least 1 non-zero number.")

else:
  print("Smallest number:",smallest(uList),"\n")

#Write a recursive function that counts up from 0 to 10.
def count_up(value=0,stop=11):
  if value<stop:
    print(value, end=" ")
    count_up(value+1,stop)

count_up()

print("\n")

#now count down from 10 to 0
def count_down(value=0,stop=11):
  if value<stop:
    count_down(value+1,stop)
    print(value, end=" ")

count_down()

print("\n")

#Define a function that returns the factorial of a user input number "the normal way," then define a recursive function that does the same thing.
def fact_norm(value):                 #normal way
  fact=1
  for x in range(value,0,-1):
    fact*=x
  return fact

def factorial(value):                 #using recursive
  if value>0:
    return value* factorial(value-1)
  return 1

uFact=int(input("Enter an integer: "))

print(str(uFact)+"!=", fact_norm(uFact))
print(str(uFact)+"!=", factorial(uFact),"\n")

#Write a recursive function that takes the sum of all integers between 2 user input numbers.
def sumUp(stop,start=0):
  if start<=stop:
    return start+ sumUp(stop,start+1)
  return 0

num1=int(input("Enter an integer: "))
num2=int(input("Enter an integer: "))

print("The sum of all numbers between",num1,"and",num2,"is:",sumUp(stop=num2,start=num1),"\n")

#Write a program that checks if a list of numbers is ordered i.e., ascending order. The program will include a function called check_order() which will take a list as input, check if it is ordered, and return True or False accordingly.
def check_order(aList):
  if aList==[]:
    return "True."

  else:
    for x in range(len(aList)-1):
      if aList[x]>aList[x+1]:
        return "False."

  return "True."

aList=[]

while(True):
  uNum=input("Enter a number, or enter \"stop\" to stop: ")
  if uNum=="stop":
    break
  else:
    aList.append(int(uNum))

print(check_order(aList),"\n")