first = 1
second = 1
#end=" " removes the newline char after print() and replaces it with a space

print(first, second, end=" ")
for x in range(10):
   nextNum = (first + second)
   print(nextNum, end=" ")
   first = second
   second = nextNum

print("\n")

#Print every other number between 1 and 10 using a For loop

#Using the loop variable
for x in range(1, 10, 2):
   print(x, end=" ")
  
print("\n")

#doing it manually
val = 1
for x in range (5):
   print(val, end= " ")
   val = val + 2
