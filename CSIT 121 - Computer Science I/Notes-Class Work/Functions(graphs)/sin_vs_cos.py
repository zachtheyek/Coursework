import numpy as np          
import matplotlib.pyplot as plt
import math

x = np.arange(0, 2*math.pi, 0.1) 
y1 = np.sin(x)
y2 = np.cos(x)
plt.plot(x, y1, label="y=sin(x)")
plt.plot(x, y2, label="y=cos(x)")

plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.title("sine vs cosine graph")
plt.legend()

plt.show()