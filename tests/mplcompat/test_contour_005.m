function result = test_contour_005
result = false;
a = figure;
[Z,x,y] = peaks;
contour(x,y,Z,5);
drawnow;
close(a);
result = true;
