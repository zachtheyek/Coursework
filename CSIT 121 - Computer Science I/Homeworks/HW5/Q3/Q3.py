myFile=open("python_wiki_original.txt","r")

newFile=open("python_wiki_encrypted.txt","w")

encryptionKey=int(input("Enter an encryption key: "))

fileData=0
x=0

print("Encrypted text: ")

while(fileData!=""):
  fileData=myFile.readline()
  for eachChar in str(fileData):
    if eachChar>='A' and eachChar<='Z':
      if ord(eachChar)+encryptionKey>ord('Z'):
        shift=ord(eachChar)+encryptionKey-ord('Z')-1
        x=chr(ord('A')+shift)
        print(x,end="")
        newFile.write(x)
      else:
        x=chr(ord(eachChar)+encryptionKey)
        print(x,end="")
        newFile.write(x)
    elif eachChar>='a' and eachChar<='z':     
      if ord(eachChar)+encryptionKey>ord('z'):
        shift=ord(eachChar)+encryptionKey-ord('z')-1
        x=chr(ord('a')+shift)
        print(x,end="")
        newFile.write(x)
      else:
        x=chr(ord(eachChar)+encryptionKey)
        print(x,end="")
        newFile.write(x)
    else:
      x=eachChar
      print(x,end="")
      newFile.write(x)

print("\n")

myFile.close()
newFile.close()


myFile=open("python_wiki_encrypted.txt","r")

encryptionKey=int(input("Enter an encryption key: "))

fileData=0

print("Original text: ")

while(fileData!=""):
  fileData=myFile.readline()
  for eachChar in str(fileData):
    if eachChar>='A' and eachChar<='Z':
      if ord(eachChar)-encryptionKey<ord('A'):
        print(chr(ord(eachChar)-encryptionKey+26),end="")
      else:
        print(chr(ord(eachChar)-encryptionKey),end="")
    elif eachChar>='a' and eachChar<='z':
      if ord(eachChar)-encryptionKey<ord('a'):
        print(chr(ord(eachChar)-encryptionKey+26),end="")
      else:
        print(chr(ord(eachChar)-encryptionKey),end="")
    else:
      print(eachChar,end="")

myFile.close()
