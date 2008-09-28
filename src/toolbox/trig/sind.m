%!
%@Module SIND Sine Degrees Function
%@@Section MATHFUNCTIONS
%@@Usage
%Computes the sine of the argument, but takes
%the argument in degrees instead of radians (as is the case
%for @|cos|). The syntax for its use is
%@[
%   y = sind(x)
%@]
%@@Examples
%The sine of 45 degrees should be @|sqrt(2)/2|
%@<
%sind(45)
%@>
%and the sine of @|30| degrees should be 0.5:
%@<
%sind(30)
%@>
%@@Tests
%@$y1=sind(x1)
%!

% Copyright (c) 2002-2007 Samit Basu
% Licensed under the GPL

function y = sind(x)
  y = sin(deg2rad(x));