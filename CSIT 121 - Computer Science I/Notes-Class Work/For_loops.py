theSum=int(0)
num=int(input("Enter an integer: "))

for i in range (0,num+1,2):
    theSum += i
    print(theSum, end=" ")

print("\n")

theSum=1
uNum=int(input("Enter an integer: "))

for n in range (1,uNum+1,1):
    theSum*=n
    print(theSum)

print("\n")

fact=1
num=int(input("Enter a positive integer: "))

for y in range (num,1,-1):
    fact*=y

print(fact)

