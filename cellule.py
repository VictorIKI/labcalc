import numpy as np
import matplotlib.pyplot as plt

x,y=np.loadtxt('Mitosi.dat',unpack=True)
plt.plot(x,y,color='blue')
plt.show()
