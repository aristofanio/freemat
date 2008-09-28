%!
%@Module ATANH Inverse Hyperbolic Tangent Function
%@@Section MATHFUNCTIONS
%@@Usage
%Computes the inverse hyperbolic tangent of its argument.  The general
%syntax for its use is
%@[
%  y = atanh(x)
%@]
%where @|x| is an @|n|-dimensional array of numerical type.
%@@Function Internals
%The @|atanh| function is computed from the formula
%\[
%   \tanh^{-1}(x) = \frac{1}{2}\log\left(\frac{1+x}{1-x}\right)
%\]
%where the @|log| (and square root) is taken in its most general sense.
%@@Examples
%Here is a simple plot of the inverse hyperbolic tangent function
%@<
%x = -0.99:.01:0.99;
%plot(x,atanh(x)); grid('on');
%mprint('atanhplot');
%@>
%@figure atanhplot
%@@Tests
%@$y1=atanh(x1)
%!


% Copyright (c) 2002-2007 Samit Basu
% Licensed under the GPL

function y = atanh(x)
  if (isinf(x))
    y = pi/2*i;
  else
    y = 0.5*log((1+x)./(1-x));
  end

  