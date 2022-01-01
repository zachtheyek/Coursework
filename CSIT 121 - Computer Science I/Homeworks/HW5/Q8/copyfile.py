txt1=input("Enter the full name of a text file: ")
txt2=input("Enter the full name of another text file: ")

file1=open(txt1,"r")
file2=open(txt2,"a")

fileData=0

while(fileData!=""):
  fileData=file1.readline()
  file2.write(fileData)

file1.close()
file2.close()

#program assumes the text files are in the same location as copyfile.py
