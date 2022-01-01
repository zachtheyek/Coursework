def sequential_search(aL, target):
  x = 0
  while(x < len(aL)/2):
    y = len(aL) - x - 1

    if aL[x] == target:
      return x

    elif aL[y] == target:
      return y
    x += 1
    
  return "Not found."

aList = [10, 20, 30, 40, 50, 60, 70, 80, 90]
target = int(input("Enter a target: "))

print(sequential_search(aList, target))

#The best case scenario for my sequential search program is O(1), and occurs when the target is either at the beginning or the end of the list.
#The worst case is if the target is in the middle of the list, or if the target doesn't exist, which is O(n/2).
#The average complexity lies somewhere in the middle.