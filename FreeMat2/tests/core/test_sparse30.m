function x = test_sparse30
ar = [1,0,3,4,5;6,2,3,5,0;0,0,0,0,2];
ai = [0,0,2,0,4;1,0,2,3,0;1,0,0,0,3];
a = complex(ar+ai*i);
A = sparse(a);
p = [3;4;5;9;10];
a(p) = complex(7+2*i);
A(p) = complex(7+2*i);
x = testeq(a,A);
