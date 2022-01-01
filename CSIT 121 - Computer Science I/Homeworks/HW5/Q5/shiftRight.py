binary=input("Enter a string: ")

string=""
i=len(binary)-1

string+=binary[i]

for j in range(i):
  string+=binary[j]

print(string) 