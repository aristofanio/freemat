function x = test_newind1
a = uint8(10*rand(10,40,5));
x = 1;
x = x & test_newind_help(a);
a = int8(10*rand(10,40,5));
x = x & test_newind_help(a);
a = uint16(10*rand(10,40,5));
x = x & test_newind_help(a);
a = int16(10*rand(10,40,5));
x = x & test_newind_help(a);
a = uint32(10*rand(10,40,5));
x = x & test_newind_help(a);
a = int32(10*rand(10,40,5));
x = x & test_newind_help(a);
a = float(10*rand(10,40,5));
x = x & test_newind_help(a);
a = double(10*rand(10,40,5));
x = x & test_newind_help(a);
a = complex(10*rand(10,40,5)+i*10*rand(10,40,5));
x = x & test_newind_help(a);
a = dcomplex(10*rand(10,40,5)+i*10*rand(10,40,5));
x = x & test_newind_help(a);

function x = test_newind_help(a)
  x = 1;
  x = x & testvol(a,a(1:10,1:40,1:5));
  x = x & testvol(a,a(:,1:40,1:5));
  x = x & testvol(a,a(1:10,:,1:5));
  x = x & testvol(a,a(1:10,1:40,:));
  x = x & testvol(a,a(1:10,:,:));
  x = x & testvol(a,a(:,1:40,:));
  x = x & testvol(a,a(:,:,1:5));
  x = x & testvol(a,a(:,:,:));
  x = x & testvol(a,a(:,:,:,:));