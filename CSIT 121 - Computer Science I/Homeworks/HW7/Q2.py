def reverse(aList):
  left = 0

  while(left < len(aList)/2):
    right = len(aList) - left - 1
    swap(aList, left, right)
    left += 1
    
  return aList

def swap(aList, left, right):
  x = aList[left]
  aList[left] = aList[right]
  aList[right] = x

myList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(reverse(myList))

#This was the most efficient reverse() function that I could come up with. It always has a complexity of O(n/2), since it has to iterate through half the list every single time no matter what.