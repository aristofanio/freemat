#include "Array.hpp"
#include "Utils.hpp"

//!
//@Module CELL Cell Array of Empty Matrices
//@@Section ARRAY
//@@Usage
//Creates a cell array of empty matrix entres.  Two seperate 
//syntaxes are possible.  The first syntax specifies the array 
//dimensions as a sequence of scalar dimensions:
//@[
//   y = cell(d1,d2,...,dn).
//@]
//The resulting array has the given dimensions, and is filled with
//all zeros.  The type of @|y| is @|cell|, a cell array.  
//    
//The second syntax specifies the array dimensions as a vector,
//where each element in the vector specifies a dimension length:
//@[
//   y = cell([d1,d2,...,dn]).
//@]
//This syntax is more convenient for calling @|zeros| using a 
//variable for the argument.  In both cases, specifying only one
//dimension results in a square matrix output.
//@@Example
//The following examples demonstrate generation of some zero arrays 
//using the first form.
//@<
//cell(2,3,2)
//cell(1,3)
//@>
//The same expressions, using the second form.
//@<
//cell([2,6])
//cell([1,3])
//@>
//@@Signature
//function cell CellFunction
//inputs varargin
//outputs y
//!
ArrayVector CellFunction(int nargout, const ArrayVector& arg) {
  return ArrayVector(Array(CellArray,ArrayVectorAsDimensions(arg)));
}