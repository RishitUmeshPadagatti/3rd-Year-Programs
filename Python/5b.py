# WAP to demonstrate how to draw a Pie Chart using matplotlib

import matplotlib.pyplot as plt

labels = ['Category A', 'Category B', 'Category C', 'Category D']
sizes = [30, 45, 15, 10]
colors = ['lightblue', 'lightcoral', 'lightgreen', 'lightsalmon']
explode = (0.1, 0, 0, 0)

plt.pie(sizes, 
    labels=labels, 
    colors=colors,
    autopct='%1.1f%%',
    shadow=True,
    explode=explode,
    startangle=140
)

plt.title("Pie Chart Example")
plt.show()