A=input("Enter  a lower-case letter: ")

print(chr(ord(A)-32))

print("\n")

for i in range(97,123,1):
    print(chr(i-32),"--> ",end="")
    print(chr(i))
