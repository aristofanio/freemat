libname='build/libtestmod.so';
import(libname,'addArrays','addArrays','int32','int32 N, float[N] a, float[N] b, float[N] &c');
import(libname,'sum_string','sum_string','int32','string a');
import(libname,'upper_string','upper_string','int32','string &a');
import(libname,'square_it','square_it','void','double &b');
a = [3,2,3,1];
b = [5,6,0,2];
c = [0,0,0,0];
d = addArrays(length(a),a,b,c);
ts = 'Hello there, peoples!';
e = sum_string(ts);
f = upper_string(ts);
g = 2;
square_it(g);
