#Imported functions
import second

print("main.py starts to execute.\n")

if __name__ == "__main__":      #if main.py isn't imported, do this.
  second.print1()
  print("main.py run directly.\n")

else:                           #if main.py is imported, do this.
  second.print2()
  print("main.py imported in another program.\n")