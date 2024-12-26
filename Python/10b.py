# Write a program for creating Maps using Plotly Libraries

import plotly.express as px

locations = ['New York', 'Los Angeles', 'Chicago', 'San Francisco']
latitudes = [40.71, 34.05, 41.87, 37.77] # between 24 and 49
longitudes = [-74.00, -118.24, -87.6298, -122.41] # between -125 and -66

# Create a map
fig = px.scatter_geo(lat=latitudes, lon=longitudes, text=locations)

# Customizing
fig.update_geos(
    projection_scale=10,
    center=dict(lon=-95, lat=38),
    visible=False,

    showcoastlines = True,
    coastlinecolor = "RebeccaPurple",

    showland = True,
    landcolor = "LightGreen",

    showocean = True,
    oceancolor="LightBlue",
    
    showlakes = True,
    lakecolor = "LightBlue"
)

fig.update_layout(title_text="Sample US Map", title_x=0.5)

fig.show()