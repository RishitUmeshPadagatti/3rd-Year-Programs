# bokeh line graph using annotations and legends

from bokeh.plotting import figure, show
from bokeh.models import ColumnDataSource, Label, LabelSet
from bokeh.io import output_file

x = [1, 2, 3, 4, 5]
y = [2, 5, 6, 8, 10]

# Create a bokeh figure
p = figure(title="Line Graph with Annotations and Legends", x_axis_label="X-axis", y_axis_label="Y-axis")

# Create a data source
source = ColumnDataSource(data={'x': x, 'y': y})

# Create a line plot
p.line('x', 'y', source=source, legend_label='Line Plot', line_color='blue', line_width=2)

# Create ANNOTATIONS
label = Label(x=3, y=6, x_units='data', y_units='data', text='Annotation', 
    background_fill_color='lightgray', background_fill_alpha=0.7
)
p.add_layout(label)

# Create LEGENDS
p.legend.title = "Legend (edited)"
p.legend.label_text_font_size = '12pt'
p.legend.background_fill_alpha = 0.7

# Create a LABEL SET
labels = LabelSet(x='x', y='y', text='y', source=source,
    text_baseline='middle', text_align='center', text_font_size='12pt'
)
p.add_layout(labels)

output_file("something.html")

show(p)