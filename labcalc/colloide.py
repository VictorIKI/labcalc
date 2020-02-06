import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt('sqm_DX_001.dat', unpack=True)
plt.plot(x,y,'r')
plt.show()
