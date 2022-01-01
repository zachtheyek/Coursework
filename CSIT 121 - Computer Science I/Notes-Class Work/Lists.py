#Write a program that generates an iterable list, converts a user input string into another list, and then combines the two lists and prints the result.
myList=list(range(1,6))
string=list(input("Enter a string: "))

print(myList+string,"\n")

#Write a program that appends a number to myList; extends another list at the end of myList; then inserts another number into index 3 of myList.
myList=[1,75,4,0,86,12]
uList=[3,3,3]
uNum=6
iNum=100

myList.append(uNum)
print(myList)

myList.extend(uList)
print(myList)

myList.insert(3,iNum)
print(myList,"\n")

#Write a program that modifies a list, such that only the non-zero integers are left. Also print how many zeros were removed from the original list.
myList=[1,3,0,3,0,9,9,5,6,7,10,0]
remv=0
x=0

while(x<len(myList)):
  if myList[x]==0:
    myList.pop(x)
    remv+=1
  
  x+=1

print(myList)
print(remv,"zeros removed.\n")

#Search a list for zeros, and print at which index it's located.
myList=[4,3,8,5,9,0,6,1]

if 0 in myList:
  print("Index of target:",myList.index(0),"\n")

#Take 5 integers as input from user and put them in a list. Display that list. Find sum of all elements in the list and print the sum.
myList=[]
theSum=0

for x in range(5):
  uNum=int(input("Enter a number: "))
  myList.append(uNum)
  theSum+=uNum

print(myList)
print("Sum:",theSum,"\n")

#Assume that data refers to list of numbers, and result refers to an empty list. Write a loop that adds the nonzero values in data to the result list, keeping them in their relative positions and excluding the zeros.
data=[1,13,0,6,4,0,9,17,0,0,0,58]
result=[]

for eachChar in data:
  if eachChar!=0:
    result.append(eachChar)

print(result,"\n")

#using the range function
data=[1,13,0,6,4,0,9,17,0,0,0,58]
result=[]

for x in range(len(data)):
  if data[x]!=0:
    result.append(data[x])
  
print(result,"\n")

#Write a program that reverses a list without creating a new list.
myList=list("abcdefghi")
print("Original list:",myList)

for x in range (int(len(myList)/2)):      #We only need to run it halfway
  y=myList[x]
  myList[x]=myList[len(myList)-x-1]
  myList[len(myList)-x-1]=y

print("Reversed list:",myList,"\n")

#using pop and insert functions
myList=list("abcdefghi")
print("Original list:",myList)

for x in range (int(len(myList)/2)):
  y=myList.pop(x)
  myList.insert(len(myList)-x-1,y)

  z=myList.pop(len(myList)-x-1)
  myList.insert(x,z)

print("Reversed list:",myList,"\n")

#the easiest way
myList=list("abcdefghi")
print("Original list:",myList)

myList.reverse()
print("Reversed list:",myList)