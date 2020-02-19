import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt('walk.dat',unpack=True)
plt.scatter(0,0, color='red')
plt.plot(x,y, color='blue')
plt.xlim(-100,100)
plt.ylim(-100,100)
plt.show()
