function result = test_plot3_003
result = false;
a = figure;
h = gca;
t = linspace(0,5*pi,200);
plot3(h,cos(t),sin(t),t,'r',sin(t),cos(t),t,'linewidth',2);
drawnow;
close(a);
result = true;