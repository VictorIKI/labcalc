import numpy as np
import matplotlib.pyplot as plt

x,y = np.loadtxt('histo1.dat', unpack=True)
plt.xlabel('configurazioni energetiche')
plt.ylabel('frequenza configurazioni')
plt.bar(x,y,color='blue')
x,y = np.loadtxt('histo2.dat', unpack=True)
plt.bar(x,y,color='red')
plt.show()
