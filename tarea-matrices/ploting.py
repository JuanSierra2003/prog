import numpy as np
from matplotlib import pyplot as plt

file = open("plot_data.txt")
data_set = file.read().replace("/n","/t").split()

X = np.array([float(data_set[id]) for id in range(0, len(data_set), 2)])
Y = np.array([float(data_set[id]) for id in range(1, len(data_set), 2)])

plt.plot(X, Y, '-b')

plt.xlabel("N")
plt.ylabel("Time")

plt.show()