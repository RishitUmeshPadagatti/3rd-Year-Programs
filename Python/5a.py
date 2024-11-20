# WAP to demonstrate how to draw a Histogram Plot using matplotlib

import matplotlib.pyplot as plt

data = [10, 15, 10, 20, 25, 30, 25, 30, 30, 35, 40, 45, 45, 45, 50]

plt.hist(data, bins=5, color='blue', edgecolor='black')

plt.xlabel("Value Bins")
plt.ylabel("Frequency")
plt.title("Histogram Plot Example")
plt.grid()
plt.show()