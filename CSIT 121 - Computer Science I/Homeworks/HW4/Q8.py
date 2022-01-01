op=input("Enter an arithmetic operator (in symbols): ")

 if op=="+":
   print("x+y=",x+y)
 elif op=="-":
   print("x-y=",x-y,"\ny-x=",y-x)
 elif op=="x" or op=="*":
   print("x*y=",x*y)
 elif op=="/":
   print("x/y=",x/y,"\ny/x=",y/x)
 else:
   print("Invalid arithmetic operator.")