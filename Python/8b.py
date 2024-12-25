# WAP for plotting different types of plots using Bokeh

from bokeh.layouts import gridplot
from bokeh.plotting import figure, show, output_file
from math import pi
from bokeh.models import ColumnDataSource

# Sample data
x = [1,2,3,4,5]
y = [2,4,6,8,10]

# Create a Bokeh figure
output_file("8b.html")

# Line Plot
p1 = figure(title="Line Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p1.line(x, y, line_color='blue', line_width=2)

# Scatter Plot
p2 = figure(title="Scatter Plot", x_axis_label="X-axis", y_axis_label="Y-axis")
p2.circle(x, y, size=10, color="green", alpha=0.6)

# Sample Data for bar plot
categories = ['Category A', 'Category B', 'Category C', 'Category D']
values = [30, 45, 15, 10]

# Bar Plot
p3 = figure(x_range=categories, title="Box Plot", x_axis_label='Categories', y_axis_label='Values')
p3.vbar(x=categories, top=values, width=0.5, color='orange')

angles = [pi/4, pi/2, pi, 1.5*pi]
data = {
    'Categories': ['Category A', 'Category B', 'Category C', 'Category D'],
    'Values': [30, 45, 15, 10],
    'start_angle': angles,
    'end_angle': angles[1:] + [2*pi],
    'fill_color': ['red', 'green', 'blue', 'orange']
}
source = ColumnDataSource(data)
p4 = figure(title="Pie Chart")
p4.wedge(x=0, y=0, radius=0.4, start_angle='start_angle', end_angle='end_angle', line_color='white', fill_color='fill_color', legend_field='Categories', source=source)

# Combine plots in a grid
grid = gridplot([[p1, p2], [p3, p4]])

# Output all plots to a single file
output_file("combined_plots.html")
show(grid)