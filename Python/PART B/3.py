# Program to create a Histogram

import matplotlib.pyplot as plt

data = [1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7]

plt.hist(data, bins=5, edgecolor='black', color='red')

plt.grid()
plt.xlabel("Values")
plt.ylabel("Frequency")
plt.title("Histogram")
plt.show()