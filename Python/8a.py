# Wap to explain working with bokeh line graph using Annotations and Legends

from bokeh.plotting import figure, show
from bokeh.models import ColumnDataSource, Label, LabelSet
from bokeh.io import output_file

x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Create a Bokeh Figure
p = figure(
    title = "Line Graph with Annotations and Legends",
    x_axis_label = "X-axis",
    y_axis_label = "Y-axis"
)

# Create a data source
source = ColumnDataSource(data = {'x': x, 'y': y})

# Create a Line Plot
p.line('x', 'y', source=source, legend_label="Line Plot", line_color="blue", line_width=2)

# Create Annotations
label = Label(x=3, y=6, x_units='data', y_units='data', text='Annotation', background_fill_color='lightgray', background_fill_alpha=0.7)
p.add_layout(label)

# Create legends
p.legend.title = "Legend"
p.legend.label_text_font_size = '12pt'
p.legend.background_fill_alpha = 0.7

# Create a label set
labels = LabelSet(x='x', y='y', text='y', level='glyph', source=source, text_baseline='middle', text_align="center", text_font_size='12pt')
p.add_layout(labels)

# Output the plot to an HTML file
output_file("8a.html")

show(p)