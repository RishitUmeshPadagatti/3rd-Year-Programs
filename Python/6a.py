# WAP to illustrate Linear Plotting using matplotlib

import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

plt.plot(x, y, marker = 'o', color = "blue", linestyle = "-")

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Linear Plot Example")
plt.grid()
plt.show()