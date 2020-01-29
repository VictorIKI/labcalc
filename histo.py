import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt('histo1.dat',unpack=True)
plt.bar(x,y)
plt.show()
