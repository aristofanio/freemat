% Regression test function (black box) for randnf
% This function is autogenerated by helpgen.py
function bbtest_success = bbtest_random_randnf
  bbtest_success = 1;
NumErrors = 0;
try
  randnf(5*ones(1,9),7,1.34)
catch
  NumErrors = NumErrors + 1;
end
if (NumErrors ~= 0) bbtest_success = 0; return; end