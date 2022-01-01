#Algorithms have 4 main complexity types (ordered from best to worst): Constant(c), Logarithmic (log(n)), Linear (n), Quadratic (n^i). 
#Write a program that finds and prints the min value a list.
aList = [0, 3, 2, 18, 9, -4, 8]
minVal = aList[0]

for eachVal in aList:
  if minVal > eachVal:
    minVal = eachVal

print(minVal, "\n")         #This program has complexity of O(n), since we have to iterate through the whole list every single time.

#Write a function that checks if a letter appears in a string. If the letter appears in the string the function should return 'True' else it should return 'False'
def find_letter(string, target):
  for eachLetter in string:
    if eachLetter == target:
      return "True"
  return "False"

string = "abcdefg"
target = input("Enter a target: ")
TF = find_letter(string, target)

print(TF, "\n")         #This program has a best case complexity of O(1) if the target is the first letter in the string, worst case of O(n) if the target is the last letter or the target doesn't exist,  and the average complexity lies somewhere in between.

##Sequential Search
#Write a program that returns the index of a given value in a list, and counts the number of iterations
def find_index(aL, target):
  countIter = 0
  for eachValue in aL:
    countIter += 1
    if eachValue == target:
      return [aL.index(eachValue), countIter]

  return [-1, countIter]

#This code has an average complexity between O(1) and O(n), but we can optimize this by searching from both ends.
def find_index_op(aL, target):
  countIter = 0
  x = 0
  while(x < len(aL)/2):
    countIter += 1
    y = len(aL) - x - 1
    if aL[x] == target:
      return [x, countIter]

    elif aL[y] == target:
      return [y, countIter]
    x += 1

  return [-1, countIter]

#let's test them out
aList = [10, 20, 30, 40, 50, 60, 70, 80, 90]
target = int(input("Enter a target: "))
result = find_index(aList, target)
result_op = find_index_op(aList, target)

print("Found at:", result[0], " Iterations:", result[1])
print("Found at:", result_op[0], " Iterations:", result_op[1], "\n")
#as you can see, we've managed to halve the worst case complexity from O(n) to O(n/2)

##Binary Search
#Write a program that returns the index of a target within a sorted list, as well as count the number of iterations.
def BinarySearch(aList, target):
  left = 0                              #left-most search point
  right = len(aList) -1                 #right-most search point
  countIter = 0
  while (left <= right):
    countIter += 1
    midpoint = (left + right) // 2      #// is the floor division function
    if aList[midpoint] == target:       
      return [midpoint, countIter]      #if the midpoint of our search points is a match, then we've found the target.

    elif aList[midpoint] < target:
      left = midpoint + 1               #if the midpoint is less than our target, then the target must be in the second half of our list.

    elif aList[midpoint] > target:
      right = midpoint - 1              #vice versa, then it must be in the first half. Keep in mind this only works because our list is sorted.
    
  return [-1, countIter]

myList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
target = int(input("Enter a target number: "))

n = BinarySearch(myList, target)
print("Target found at:", n[0], "\nNumber of iterations:", n[1], "\n")
#This way of searching has complexity of O(log_2(n))

##Selection Sort
#Write a program that sorts a list by looping through and swapping the smallest number to the front.
def selectionSort(aList):
  i = 0
  while i < len(aList) - 1:
    minIndex = i
    j = i + 1
    while j < len(aList):
      if aList[j] < aList[minIndex]:
        minIndex = j
      j += 1
    
    if minIndex != i:
      swap(aList, i, minIndex)
    i += 1

def swap(aList, old_min_index, new_min_index):
  x = aList[old_min_index]
  aList[old_min_index] = aList[new_min_index]
  aList[new_min_index] = x

myList = [1, 7, 4, 12, 16, 77, 83, 83, 107, 8, 44, 11, 1, 2, 3, 9, 0]
print("Before selection sort:", myList)

selectionSort(myList)
print("After selection sort:", myList, "\n")
#Selection sort always has a complexity of O(n^2)

##Buble sort
#Write a program that sorts a list by looping through the list and comparing one item w/ the next, and swapping the bigger item to the right
def bubbleSort(aList):
  length = len(aList) - 1
  while length > 0:
    TF = 0
    for x in range(0, length):
      if aList[x] > aList[x+1]:
        swap(aList, x+1, x)
      else:
        TF += 1

    if TF == length:  
      return          #if no swaps occur throughout a loop, then the list is sorted
    else:
      length -= 1     #else we loop again


def swap(aList, old_min_index, new_min_index):
  x = aList[old_min_index]
  aList[old_min_index] = aList[new_min_index]
  aList[new_min_index] = x
    
myList = [1, 7, 4, 12, 16, 77, 83, 83, 107, 8, 44, 11, 1, 2, 3, 9, 0]
print("Before bubble sort:", myList)

bubbleSort(myList)
print("After selection sort:", myList, "\n")
#The best case complexity is O(n), and the average and worst case is O(n^2).

##Insertion sort
#Write a program that loops through a list, comparing one term to the next. If the right term is less than the left term, then the program loops through everything on the left, placing the right term in right order.
def insertionSort(aList):
  i = 1
  while (i < len(aList)):
    insert = aList[i]               #we store our target number in "insert"
    j = i - 1
    while (j >= 0):                 #then we loop through everything that comes before "insert"
      if insert < aList[j]:         #if "insert" < the number before it
        aList[j + 1] = aList[j]     #then replace the number in "insert" w/ the number before it
        j -= 1
      else:                         #since we know everything before "insert" is sorted, if "insert" > the number before it, then that's where "insert" should go
        break                       #so we break the loop, and we store the index of the number before where "insert" should go  
    aList[j + 1] = insert           #we place insert in its right position 
    i += 1                          #then we move our target number index one to the right, and repeat

myList = [1, 7, 4, 12, 16, 77, 83, 83, 107, 8, 44, 11, 1, 2, 3, 9, 0]
print("Before insertion sort:", myList)

insertionSort(myList)
print("After insertion sort:", myList)
#Insertion sort has a best case complexity of O(n), and the average and worst case complexity is O(n^2)