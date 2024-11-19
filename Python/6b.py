# WAP to illustrate Linear Plotting with line

import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

plt.plot(x, y, 
    marker='o',
    markersize=8,
    color='blue' , 
    linestyle='--',
    linewidth=2,
    label='Line Example' # no use
)

plt.xlabel("X-axis")
plt.ylabel("Y-axis")
plt.title("Linear plot with Line Formatting")
plt.grid()

plt.show()