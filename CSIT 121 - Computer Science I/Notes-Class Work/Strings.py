#Write a program that prints myString in reverse order 
myString="This is a string."

i=len(myString)-1

while(i>=0):
  print (myString[i], end="")
  i-=1

print("\n")

#use string manipulation 
myString="This is a string."

j=1

while(j<=len(myString)):
  print (myString[-j], end="")
  j+=1

print("\n")

#Save the program written above (the reversed string) in a seperate string 
myString="This is a string."

reversedString=""

k=1

while(k<=len(myString)):
  reversedString += myString[-k]
  k+=1

print(reversedString,"\n")

#Write a program that implements a Caesar Cipher to a string (letter + key = encrypted letter).
key=int(input("Enter an encryption key: "))

string=input("Original string: ")

for m in string:
  print(chr(ord(m)+key), end="")

print("\n")

#Write a Caesar Cipher that wraps around alphabets
key=int(input("Enter an encryption key: "))

string=input("Original string: ")

for m in string:
  if ord(m)>=ord('A') and ord(m)<=ord('Z'):
    if ord(m)+key>ord('Z'):
      shift=ord(m)+key-ord('Z')-1
      print(chr(ord('A')+shift), end="")
    else:
      print(chr(ord(m)+key), end="")
  elif ord(m)>=ord('a') and ord(m)<=ord('z'):
    if ord(m)+key>ord('z'):
      shift=ord(m)+key-ord('z')-1
      print(chr(ord('a')+shift), end="")
    else:
      print(chr(ord(m)+key), end="")
  else:
    print(m, end="")

print("\n")

#Write a decoder, i.e. take the encrypted text and the key and print the original message.
key=int(input("Enter an encryption key: "))

encrypted=input("Enter an encrypted message: ")

for m in encrypted:
  if ord(m)>=ord('A') and ord(m)<=ord('Z'):
    if ord(m)-key<ord('A'):
      print(chr(ord(m)-key+26), end="")
    else:
      print(chr(ord(m)-key), end="")
  elif ord(m)>=ord('a') and ord(m)<=ord('z'):
    if ord(m)-key<ord('a'):
      print(chr(ord(m)-key+26), end="")
    else:
      print(chr(ord(m)-key), end="")
  else:
    print(m, end="")

print("\n")

#Write a program that converts a binary numbers into it's decimal equivalent (ex: Input: 1101, Output: 13)

#using lists
binary=input("Enter a binary number: ")

binaryList=[]

for n in range(0,len(binary)):
  binaryList.append(2**n)

binaryList.reverse()

decimal=0

for p in range(0,len(binary)):
  if binary[p]=="1":
    decimal+=binaryList[p]

print("Binary --> Decimal:",decimal,"\n")

#without using lists
binary=input("Enter a binary number: ")

decimal=0

n=0
p=len(binary)-1

while(n<len(binary)):
  if binary[n]=="1":
    decimal+=2**p
  p-=1
  n+=1

print("Binary --> Decimal:",decimal,"\n")

#without using an if statement
binary=input("Enter a binary number: ")

decimal=0

exponent=len(binary)-1

for n in binary:
  decimal+=int(n)*(2**exponent)
  exponent-=1

print("Binary --> Decimal:",decimal,"\n")

#Write a program that converts a decimal number into its binary equivalent

#using lists
decimal=int(input("Enter a decimal number: "))

decimalList=[]

q=0

if decimal==0:
  print("Decimal --> Binary: 0\n")
else:
  while(q<decimal):
    if 2**q<=decimal:
      decimalList.append(2**q)
    else:                                     
      break
    q+=1

  decimalList.reverse()

  binary=""

  r=0

  while(r<len(decimalList)):
    if decimal-decimalList[r]>=0:
      decimal-=decimalList[r]
      binary+="1"
    else:                                     
      binary+="0"
    r+=1

  print("Decimal --> Binary:",binary,"\n")

#without using lists
decimal=int(input("Enter a decimal number: "))

binary=""

q=0

if decimal==0:
  print("Decimal --> Binary: 0\n")
else:
  while(q<decimal):
    if 2**q<=decimal:
      q+=1
    else:                                     
      q-=1
      break

  while(q>=0):
    if decimal-2**q>=0:
      decimal-=2**q
      binary+="1"
    else:
      binary+="0"
    q-=1

  print("Decimal --> Binary:",binary,"\n")

#using mod

"""
% is the mod function and returns the remainder
/ is floating point division
// is floor division and returns result rounded to nearest integer
"""

decimal=int(input("Enter a decimal number: "))

binary=""

if decimal==0:
  print("Decimal --> Binary: 0\n")
else:
  while (decimal>0):
    remainder=decimal%2
    decimal=decimal//2
    binary=str(remainder)+binary  #we want the remainder to be concatenated in front

  print("Decimal --> Binary:",binary)
