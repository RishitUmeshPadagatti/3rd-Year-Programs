# WAP for plotting different types of plots using Bokeh

from bokeh.plotting import figure, show, output_file
from math import pi

# Sample data
x = [1,2,3,4,5]
y = [2,4,6,8,10]

# Create a Bokeh figure
output_file("8b.html")

# Line Plot
p1 = figure(title="Line Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p1.line(x, y, line_color='blue', line_width=2)
show(p1)

# Scatter Plot
p2 = figure(title="Scatter Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p2.circle(x, y, size=10, color="green", alpha=0.6)
show(p2)

# Sample Data for bar plot
# TODO