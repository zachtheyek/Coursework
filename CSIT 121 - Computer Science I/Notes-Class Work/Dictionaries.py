#Write a program that adds 2 new keys and values to a dictionary. Then lists out all the keys and associated values in that dictionary.
myDict={'a':"Red",'b':"Blue",'c':"Green"}

myDict.update({'d':"Yellow"})
myDict['banana']="Yellow"                #We can have similar values, but not keys

print("Dictionary:",myDict)

for key in myDict:
  print("Key:",key,end=", ")
  print("Value:",myDict[key])

print("")

#Now pop a value in the dictionary, and print the popped value and the new dictionary.
if 'd' in myDict:
  print("Popped value:",myDict.pop('d'))
  print(myDict)

else:
  print("Key not found.")

print("")

#Instead of printing the keys and values separately, print all the keys and values as an iterable list (tuples).
print(list(myDict.items()),"\n")

#Write a program that prints all the keys and values of a dictionary as 2 separate lists. Then print the value at a user-given key. Lastly, print the length of the dictionary, and then clear the dictionary.
myDict={1:"Bob",5:"James",12:"Greg",13:"Wayne",17:"Michael",20:"Robin"}

print("Keys:",list(myDict))
print("Values:",list(myDict.values()),"\n")

uKey=input("Enter a key: ")
print("Value for key "+str(uKey)+":", myDict.get(int(uKey),"Key not found."),"\n")

print("Length:",len(myDict))

myDict.clear()

print("")

#Write a program that adds all "values" in a dictionary and prints the sum.
myDict={'a':100,'b':-12,'c':63}

theSum=0

for eachKey in myDict:
  theSum+=myDict[eachKey]

print("Sum:",theSum,"\n")

#Write a program that finds the largest key in a dictionary and displays the key value pair. Assume keys are all positive integers.
myDict={'a':10,'b':46,'c':3,'d':18,'e':94,'f':13}

bigKey=list(myDict)[0]

for eachKey in myDict:
  if myDict[eachKey]>myDict[bigKey]:
    bigKey=eachKey

print("Largest value: "+str(myDict[bigKey])+", Key: "+str(bigKey)+"\n")

#Write a program that counts the frequency of letters in an input string.
myDict={}
string=input("Enter a string: ")

for eachChar in string:
  if ord(eachChar)>=ord('a') and ord(eachChar)<=ord('z'):
    eachChar=chr(ord(eachChar)-32)
    
  if ord(eachChar)>=ord('A') and ord(eachChar)<=ord('Z'):
    if eachChar in myDict:
     myDict[eachChar]+=1

    else:
      myDict[eachChar]=1

while(myDict!={}):
  bigKey=list(myDict)[0]

  for eachKey in myDict:
    if myDict[eachKey]>myDict[bigKey]:
      bigKey=eachKey

  if myDict[bigKey]==1:
    print("The letter "+str(bigKey),"appears:",myDict[bigKey],"time.")

  else:
    print("The letter "+str(bigKey),"appears:",myDict[bigKey],"times.")

  myDict.pop(bigKey)
