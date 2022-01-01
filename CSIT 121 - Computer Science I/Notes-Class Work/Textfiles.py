import os
import os.path as op
import random
import csv

#Write a code segment that opens a file named myfile.txt for input and prints the number of lines in the file.
if op.exists("myfile.txt"):
  newFile=open("myfile.txt","r")

  lines=0

  while(newFile.readline()!=""):
    lines+=1

  print("number of lines:",lines)

  newFile.close()

else:
  print("File does not exist.")

print("")

#using a for loop 
if op.exists("myfile.txt"):
  newFile=open("myfile.txt","r")

  lines=0

  for eachLine in newFile:
    lines+=1

  print("number of lines:",lines)

  newFile.close()

else:
  print("File does not exist.")

print("")

#Assume that a file contains integers separated by new lines. Write a code segment that opens the file and prints the average value of the integers. 
if op.exists("integer.txt"):
  newFile=open("integer.txt","r")

  total=0
  lines=0

  for eachLine in newFile:
    total+=int(eachLine)
    lines+=1

  print("Average value:",total/lines)

  newFile.close()

else:
  print("File does not exist.")

print("")

#Write a program that prints a list of text files in your current directory
currentDir=os.getcwd()                             #cwd: current working directory
fileList=os.listdir(currentDir)

for fileName in fileList:
  if ".txt" in fileName:
    print(fileName)

print("")

#Write a program that prompts the user for a new directory, then make that directory if it doesn't already exist.

dirName=input("Enter a new directory: ")

if op.exists(dirName) and op.isdir(dirName):       #isdir: Is Directory
  print("Directory already exists.")

else:
  os.mkdir(dirName)                                #mkdir: Make Directory
  print("Directory created.")

print("")

#Write a program that prompts the user for a file name. If the file exists, the program should print its contents on the terminal. Otherwise, it should print an error message.
fileName=input("Enter a file name: ")

if op.exists(fileName):
  newFile=open(fileName,"r")
  for eachLine in newFile:
    print(eachLine,end="")

  print("\n")

  newFile.close()

else:
  print("File does not exist.\n")

#Write a program that creates 10 files in a directory with any data. The 10 files will have 10 different names generated automatically by your program. Your program will also make sure before creating a file if a file with the same name exists already, if so, it will not use this name. 
fileName=""
x=0

while(x<10):
  fileName="file"+str(random.randint(0,100))+".txt"

  if not op.exists(fileName):
    myFile=open(fileName,"w")
    myFile.write(str(random.randint(100,1000)))
    myFile.close()
  
  else:
    x-=1

  x+=1

#Write a program that lists the data stored in each row of a .csv file.
fileName=input("Enter a file name: ")

if op.exists(fileName):
  with open(fileName) as csvFile:
    csvRead=csv.reader(csvFile,delimiter=",")         #delimiter = separator

    for eachRow in csvRead:
      print(eachRow)
    
    print("")

    csvFile.close()

else:
  print("File does not exist.\n")

#the manual way 
fileName=input("Enter a file name: ")

if op.exists(fileName):
  csvFile=open(fileName,"r")

  for eachRecord in csvFile:
    fields=eachRecord.strip("\n").split(",")
    print(fields)

  print("")

  csvFile.close()

else:
  print("File does not exist.\n")

#Calculate the average cost of all the items in cost.csv 

if op.exists("cost.csv"):
  total=0
  items=0

  with open("cost.csv") as csvFile:
    csvRead=csv.reader(csvFile,delimiter=",")       

    for eachRow in csvRead:
      total+=int(eachRow[3])
      items+=1
    
    print("Average cost:",total/items)

    csvFile.close()

else:
  print("File does not exist.")
