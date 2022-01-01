import numpy as np          
import matplotlib.pyplot as plt

x = ['Adam', 'Bob', 'James', 'Susan', 'Jessica']
y = [92, 44, 69, 98, 41]
plt.bar(x, y)

plt.xlabel("Names")
plt.ylabel("Scores")
plt.title("Final grades")

plt.show()