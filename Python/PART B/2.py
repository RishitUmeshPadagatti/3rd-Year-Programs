# Legends

import matplotlib.pyplot as plt

categories = ["Category A", "Category B", "Category C", "Category D"]
values_set1 = [25, 50, 75, 100]
values_set2 = [35, 45, 60, 80]

plt.bar(categories, values_set1, label="Set 1", color="blue")

plt.bar(categories, values_set2, label="Set 2", color="green", alpha=0.6)

plt.xlabel("Categories")
plt.ylabel("Values")
plt.title("Bar Plot with Legends")
plt.legend()

plt.show()