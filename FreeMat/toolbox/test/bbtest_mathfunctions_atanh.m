% Regression test function (black box) for atanh
% This function is autogenerated by helpgen.py
function bbtest_success = bbtest_mathfunctions_atanh
  bbtest_success = 1;
NumErrors = 0;
try
  x = -0.99:.01:0.99;
catch
  NumErrors = NumErrors + 1;
end
try
  plot(x,atanh(x)); grid('on');
catch
  NumErrors = NumErrors + 1;
end
try
  mprint('atanhplot');
catch
  NumErrors = NumErrors + 1;
end
if (NumErrors ~= 0) bbtest_success = 0; return; end