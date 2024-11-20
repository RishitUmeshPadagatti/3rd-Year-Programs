# WAP which explain uses of customizing seaborn plots with Aesthetic functions

import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")  # Load a built-in dataset from seaborn
sns.set(style="whitegrid", palette="Set1")  # Set seaborn style and color palette

# Create a customized Scatter Plot
plt.figure(figsize=(8, 6))
sns.scatterplot(
    x="total_bill", 
    y="tip", 
    data=tips, 
    hue="time", 
    style="sex", 
    s=100, 
    palette="Set2"
)
plt.title("Customized Scatter Plot")
plt.xlabel("Total Bill")
plt.ylabel("Tip")
plt.legend(title="Title of the Day")
plt.show()

# Create a customized Histogram
plt.figure(figsize=(8,6))
sns.histplot(
    tips["total_bill"],
    bins=20,
    kde=True,
    color="skyblue",
    line_kws={"color": "red"}
)
plt.title("Customized Histogram")
plt.xlabel("Total Bill")
plt.ylabel("Frequency")
plt.grid()
plt.show()

# Create a customized Box Plot
plt.figure(figsize=(8,6))
sns.boxplot(
    x="day",
    y="total_bill",
    data=tips,
    palette="husl"
)
plt.title("Customized Box Plot")
plt.xlabel("Day")
plt.ylabel("Total Bill")
plt.show()