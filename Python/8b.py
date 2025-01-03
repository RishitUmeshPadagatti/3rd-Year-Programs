# WAP for plotting different types of plots using Bokeh

from bokeh.plotting import show, figure, output_file
from bokeh.models import ColumnDataSource
from math import pi

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

categories = ["Category A", "Category B", "Category C", "Category D"]
values = [30, 45, 15, 10]

angles = [pi/4, pi/2, pi, 1.5*pi]

# Line Plot
p1 = figure(title="Line Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p1.line(x, y, line_color="blue", line_width=2)
show(p1)

# Scatter Plot
p2 = figure(title="Scatter Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p2.circle(x, y, size=10, color="green", alpha=0.6)
show(p2)

# Bar Plot
p3 = figure(x_range=categories, title="Box Plot", x_axis_label="X axis", y_axis_label="Y axis")
p3.vbar(x=categories, top=values, width=0.5, color="orange")
show(p3)

# Pie Chart
data = {
    'Categories': categories,
    'Values': values,
    'start_angle': angles,
    'end_angle': angles[1:] + [2*pi],
    'fill_color': ['red', 'blue', 'green', 'orange']
}
source = ColumnDataSource(data)
p4 = figure(title="Pie Chart")
p4.wedge(x=0, y=0, radius=0.4, start_angle='start_angle', end_angle='end_angle', line_color='white', fill_color='fill_color', legend_field='Categories', source=source)
show(p4)