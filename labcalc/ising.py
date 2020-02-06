import numpy as np
import matplotlib.pyplot as plt


plt.xlabel('configurazioni energetiche')
plt.ylabel('frequenza configurazioni')
x,y = np.loadtxt('histo2.dat', unpack=True)
plt.bar(x,y,color='red')
x,y = np.loadtxt('histo1.dat', unpack=True)
plt.bar(x,y,color='blue')

plt.show()
