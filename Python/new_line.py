# import modules
from bokeh.plotting import figure, output_notebook, show
  
# output to notebook
output_notebook()
  
# create figure
p = figure(plot_width = 400, plot_height = 400)
   
# add a line renderer
p.line([1, 2, 3, 4, 5], [3, 1, 2, 6, 5], 
        line_width = 2, color = "green")
  
# show the results
show(p)
