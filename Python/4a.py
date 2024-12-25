# Write a Python program to Demonstrate how to Draw a Bar Plot using Matplotlib.

import matplotlib.pyplot as plt

categories = ["Category A", "Category B", "Category C", "Category D"]
values = [10, 30, 20, 40]

plt.bar(categories, values, color="blue")

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Bar Plot")

plt.show()