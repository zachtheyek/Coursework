import os
import os.path as op

def view_contents():
  cwd={}
  print("Files in your current working directory:")

  for eachFile in os.listdir():
    print(eachFile)

    fileContent=""
    if op.isdir(eachFile):
      for files in os.listdir(eachFile):
        fileContent+=files+"\n"

    else:
      with open(eachFile, 'r') as f:
        for eachLine in f:
          fileContent+=eachLine

    cwd[eachFile]=fileContent

  uFile=input("\nEnter the file you'd like to view: ")

  if uFile in cwd:
    print("\nContents of", uFile, "start here.\n---------------------------\n\n")
    print(cwd.get(uFile))
    print("\n\n---------------------------\nContents of", uFile, "end here.")

  else:
    print("File does not exist.")

view_contents()