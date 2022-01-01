print("This program will print the sum of 5 squares.")

theSum=0

for i in range(5):
    num=int(input("Enter a number: "))
    theSum+=num**2

    #We could also write it all in one line, as such:
    #theSum+=int(input("Enter a number: "))**2

print(theSum)
