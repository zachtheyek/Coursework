binary=input("Enter a string: ")

string=""
x=1

while(x<len(binary)):
  string+=binary[x]
  x+=1

string+=binary[0]

print(string) 