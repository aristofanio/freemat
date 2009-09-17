% Regression test function (black blox) for FreeMat v4.0
% This function is autogenerated by helpgen.
function bbtest_success = bbtest_full
  bbtest_success = 1;
NumErrors = 0;
try
  a = [1,0,4,2,0;0,0,0,0,0;0,1,0,0,2]

catch
  NumErrors = NumErrors + 1;
end
try
  A = sparse(a)

catch
  NumErrors = NumErrors + 1;
end
try
  full(A)

catch
  NumErrors = NumErrors + 1;
end
if (NumErrors ~= 0) bbtest_success = 0; return; end
