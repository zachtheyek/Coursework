#second.py

def print1():
  print("One")

def print2():
  print("Two")

if __name__ == "__main__":    #if second.py isn't imported, do this.
  print1()
  print("second.py run directly.\n")

else:                         #if second.py is imported, do this.
  print2()
  print("second.py imported in another program.\n")