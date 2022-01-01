def isSorted(aList):

  if aList==[]:
    return "True."

  else:
    for x in range (len(aList)-1):
      if aList[x]>aList[x+1]:
       return "False."
  
  return "True."

aList=[]

while(True):
  uNum=input("Enter a number, or enter \"stop\" to stop: ")
  if uNum=="stop":
    break
  else:
    aList.append(int(uNum))

print(isSorted(aList))