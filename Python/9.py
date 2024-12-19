# Write a Python program to draw 3D plots using Plotly Libraries

import plotly.graph_objects as go
import numpy as np

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)

# 3d function
Z = np.sin(np.sqrt(X**2 + Y**2))

# 3d surface with plotly
fig = go.Figure(data=go.Surface(z=Z, x=x, y=y))
fig.update_layout(scene=dict(zaxis_title="Z-axis", xaxis_title="X-axis", yaxis_title="Y-axis"), title="3D Surface Plot")

fig.show()