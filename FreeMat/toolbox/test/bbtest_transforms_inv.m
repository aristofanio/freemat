% Regression test function (black box) for inv
% This function is autogenerated by helpgen.py
function bbtest_success = bbtest_transforms_inv
  bbtest_success = 1;
NumErrors = 0;
try
  a = randi(zeros(3),5*ones(3))
catch
  NumErrors = NumErrors + 1;
end
try
  b = inv(a)
catch
  NumErrors = NumErrors + 1;
end
try
  a*b
catch
  NumErrors = NumErrors + 1;
end
try
  b*a
catch
  NumErrors = NumErrors + 1;
end
if (NumErrors ~= 0) bbtest_success = 0; return; end