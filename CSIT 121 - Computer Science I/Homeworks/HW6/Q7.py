import os
import os.path as op

def main():
  displayFiles(os.getcwd())

def displayFiles(pathname):
  if op.exists(pathname):
    if op.isfile(pathname):
      print("File name:", pathname)
      print("contents start\n-------------------------\n")

      with open(pathname, 'r') as f:
        print(f.read(), "\n")
        
      print("-------------------------\nends\n")

    else:
      print("Directory name:", pathname)
      for eachItem in os.listdir(pathname):
        newItem = op.join(pathname, eachItem)
        displayFiles(newItem)
        
  else:
    print("File does not exist.\n")


if __name__ == "__main__":
  main()