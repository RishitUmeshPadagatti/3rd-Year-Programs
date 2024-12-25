# Write a Python program to Demonstrate how to Draw a Scatter Plot using Matplotlib.

import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 9, 10]

plt.scatter(x, y, 
    color="blue", 
    marker="o", 
    alpha=0.6, 
    edgecolor='red'
)

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Scatter Plot")

plt.show()