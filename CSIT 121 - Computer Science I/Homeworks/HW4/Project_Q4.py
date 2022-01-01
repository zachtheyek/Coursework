index=0.6

height=int(input("Initial height of ball (in ft): "))
bounce=int(input("Number of times the ball bounces: "))

x=0
theSum=0

if bounce==0:
  print("Total distance travelled= 0ft")
elif bounce<0:
  print("Number of bounces cannot be less than 0.")
elif height<0:
  print("Initial height cannot be less than 0.")
elif bounce>=1:
  while(x<bounce):
      theSum+=height
      height=height*index
      theSum+=height
      x+=1
  print("Total distance travelled=",theSum,"ft")