import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt('walk.dat',unpack=True)
plt.plot(x,y, color='black')
plt.xlim(-100,100)
plt.ylim(-100,100)
plt.show()
