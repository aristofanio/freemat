#include "Operators.hpp"
#include "Array.hpp"
#include "SparseMatrix.hpp"

struct OpBitAnd {
  template <typename T>
  static inline T func(T A, T B) {return T(uint32(A) & uint32(B));}
  template <typename T>
  static inline void func(const T& Ar, const T& Ai,
		   const T& Br, const T& Bi,
		   T& cr, T& ci) {
    cr = T(uint32(Ar) & uint32(Br));
    ci = T(uint32(Ai) & uint32(Bi));
  }
};

struct OpBitOr {
  template <typename T>
  static inline T func(T A, T B) {return T(uint32(A) | uint32(B));}
  template <typename T>
  static inline void func(const T& Ar, const T& Ai,
		   const T& Br, const T& Bi,
		   T& cr, T& ci) {
    cr = T(uint32(Ar) | uint32(Br));
    ci = T(uint32(Ai) | uint32(Bi));
  }
};

struct OpBitXor {
  template <typename T>
  static inline T func(T A, T B) {return T(uint32(A) ^ uint32(B));}
  template <typename T>
  static inline void func(const T& Ar, const T& Ai,
		   const T& Br, const T& Bi,
		   T& cr, T& ci) {
    cr = T(uint32(Ar) ^ uint32(Br));
    ci = T(uint32(Ai) ^ uint32(Bi));
  }
};
  
struct OpBitCmp {
  template <typename T>
  static inline T func(T A) {return T(~uint32(A));}
  template <typename T>
  static inline void func(const T &Ar, const T &Ai, T& Cr, T& Ci) {
    Cr = T(~uint32(Ar));
    Ci = T(~uint32(Ai));
  }
};

//!
//@Module BITAND Bitwise Boolean And Operation
//@@Section BINARY
//@@Usage
//Performs a bitwise binary and operation on the two arguments and
//returns the result.  The syntax for its use is
//@[
//   y = bitand(a,b)
//@]
//where @|a| and @|b| are multi-dimensional unsigned integer arrays.
//The and operation is performed using 32 bit unsigned intermediates.  Note that if a
//or b is a scalar, then each element of the other array is and'ed with
// that scalar.  Otherwise the two arrays must match in size.
//@@Example
//@<
//bitand(uint16([1,16,255]),uint16([3,17,128]))
//bitand(uint16([1,16,255]),uint16(3))
//@>
//@@Tests
//@{ test_bitand1.m
//function test_val = test_bitand1
// test_val = all(bitand([1,5,42],3) == [1 1 2]);
//@}
//@@Signature
//function bitand BitandFunction
//inputs a b
//outputs y
//!
ArrayVector BitandFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 2)
    throw Exception("bitand requires at least two arguments");
  return ArrayVector(DotOp<OpBitAnd>(arg[0],arg[1]));
}

//!
//@Module BITOR Bitwise Boolean Or Operation
//@@Section BINARY
//@@Usage
//Performs a bitwise binary or operation on the two arguments and
//returns the result.  The syntax for its use is
//@[
//   y = bitor(a,b)
//@]
//where @|a| and @|b| are multi-dimensional unsigned integer arrays.
//The and operation is performed using 32 bit unsigned intermediates.  Note that if a
//or b is a scalar, then each element of the other array is or'ed with
//that scalar.  Otherwise the two arrays must match in size.
//@@Example
//@<
//bitand(uint16([1,16,255]),uint16([3,17,128]))
//bitand(uint16([1,16,255]),uint16(3))
//@>
//@@Tests
//@{ test_bitor1.m
//function test_val = test_bitor1
//  test_val = all(bitor([1,5,42],3) == [3 7 43]);
//@}
//@@Signature
//function bitor BitorFunction
//inputs a b
//outputs y
//!
ArrayVector BitorFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 2)
    throw Exception("bitor requires at least two arguments");
  return ArrayVector(DotOp<OpBitOr>(arg[0],arg[1]));
}

//!
//@Module BITXOR Bitwise Boolean Exclusive-Or (XOR) Operation
//@@Section BINARY
//@@Usage
//Performs a bitwise binary xor operation on the two arguments and
//returns the result.  The syntax for its use is
//@[
//   y = bitxor(a,b)
//@]
//where @|a| and @|b| are multi-dimensional unsigned integer arrays.
//The and operation is performed using 32 bit unsigned intermediates.  Note that if a
//or b is a scalar, then each element of the other array is xor'ed with
// that scalar.  Otherwise the two arrays must match in size.
//@@Example
//@<
//bitand(uint16([1,16,255]),uint16([3,17,128]))
//bitand(uint16([1,16,255]),uint16(3))
//@>
//@@Tests
//@{ test_bitxor1.m
//function test_val = test_bitxor1
//  test_val = all(bitxor([1,5,42],3) == [2 6 41]);
//@}
//@@Signature
//function bitxor BitxorFunction
//inputs a b
//outputs y
//!
ArrayVector BitxorFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 2)
    throw Exception("bitxor requires at least two arguments");
  return ArrayVector(DotOp<OpBitXor>(arg[0],arg[1]));
}

// FIXME
//@@Signature
//function bitcmp_cpp BitcmpFunction
//inputs a
//outputs y
ArrayVector BitcmpFunction(int nargout, const ArrayVector& arg) {
  return ArrayVector(UnaryOp<OpBitCmp>(arg[0]).toClass(arg[0].dataClass()));
}

//!
//@Module INT2BIN Convert Integer Arrays to Binary
//@@Section TYPECAST
//@@Usage
//Computes the binary decomposition of an integer array to the specified
//number of bits.  The general syntax for its use is
//@[
//   y = int2bin(x,n)
//@]
//where @|x| is a multi-dimensional integer array, and @|n| is the number
//of bits to expand it to.  The output array @|y| has one extra dimension
//to it than the input.  The bits are expanded along this extra dimension.
//@@Example
//The following piece of code demonstrates various uses of the int2bin
//function.  First the simplest example:
//@<
//A = [2;5;6;2]
//int2bin(A,8)
//A = [1;2;-5;2]
//int2bin(A,8)
//@>
//@@Tests
//@{ test_int2bin1.m
//function test_val = test_int2bin1
//  test_val = all(int2bin([4;3;2;1],3)==[1,0,0;0,1,1;0,1,0;0,0,1]);
//@}
//@@Signature
//function int2bin Int2BinFunction
//inputs x bits
//outputs y
//!

struct OpInt2Bin {
  template <typename T>
  static inline void func(const ConstSparseIterator<T> &, SparseSlice<T>&) {
    throw Exception("int2bin not supported for sparse matrices");
  }
  template <typename T>
  static inline void func(const ConstComplexSparseIterator<T> &,
			  SparseSlice<T>&, SparseSlice<T>&) {
    throw Exception("int2bin not supported for sparse matrices");
  }
  template <typename T>
  static inline void func(const BasicArray<T> &src, BasicArray<T>& dest) {
    int numbits = int(dest.length());
    if (numbits < 1) numbits = 1;
    int64 value = int64(src[1]);
    for (int i=0;i<numbits;i++) {
      dest[numbits-i] = T(value & 1);
      value >>= 1;
    }
  }
  template <typename T>
  static inline void func(const BasicArray<T> &src_real, const BasicArray<T> &src_imag,
			  BasicArray<T>& dest_real, BasicArray<T>& dest_imag) {
    func(src_real,dest_real);
    func(src_imag,dest_imag);
  }
};

ArrayVector Int2BinFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 2)
    throw Exception("int2bin requires at least two arguments");
  return ArrayVector(VectorOp<OpInt2Bin>(arg[0],arg[1].asInteger(),
					 qMax(1,arg[0].dimensions().lastSingular())).toClass(Bool));
}

//!
//@Module BIN2INT Convert Binary Arrays to Integer
//@@Section TYPECAST
//@@Usage
//Converts the binary decomposition of an integer array back
//to an integer array.  The general syntax for its use is
//@[
//   y = bin2int(x)
//@]
//where @|x| is a multi-dimensional logical array, where the last
//dimension indexes the bit planes (see @|int2bin| for an example).
//By default, the output of @|bin2int| is unsigned @|uint32|.  To
//get a signed integer, it must be typecast correctly.  A second form for
//@|bin2int| takes a @|'signed'| flag
//@[
//   y = bin2int(x,'signed')
//@]
//in which case the output is signed.
//@@Example
//The following piece of code demonstrates various uses of the int2bin
//function.  First the simplest example:
//@<
//A = [2;5;6;2]
//B = int2bin(A,8)
//bin2int(B)
//A = [1;2;-5;2]
//B = int2bin(A,8)
//bin2int(B)
//int32(bin2int(B))
//@>
//@@Tets
//@{ test_bin2int1.m
//function test_val = bin2int1
//   A = floor(rand(4,4,3)*10);
//   B = int2bin(A,4);
//   C = bin2int(B);
//   test_val = issame(A,C);
//@}
//@@Signature
//function bin2int Bin2IntFunction
//inputs x flag
//outputs y
//!
struct OpBin2Int {
  template <typename T>
  static inline void func(const ConstSparseIterator<T> &, SparseSlice<T>&) {
    throw Exception("int2bin not supported for sparse matrices");
  }
  template <typename T>
  static inline void func(const ConstComplexSparseIterator<T> &,
			  SparseSlice<T>&, SparseSlice<T>&) {
    throw Exception("int2bin not supported for sparse matrices");
  }
  template <typename T>
  static inline void func(const BasicArray<T> &src, BasicArray<T>& dest) {
    int numbits = int(src.length());
    uint64 value = (src[1] != 0) ? 1 : 0;
    for (int j=1;j<numbits;j++) {
      value <<= 1;
      value |= (src[j+1] != 0) ? 1 : 0;
    }
    dest[1] = value;
  }
  template <typename T>
  static inline void func(const BasicArray<T> &src_real, const BasicArray<T> &src_imag,
			  BasicArray<T>& dest_real, BasicArray<T>& dest_imag) {
    func(src_real,dest_real);
    func(src_imag,dest_imag);
  }
};

ArrayVector Bin2IntFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 1)
    throw Exception("bin2int requires at least one arguments");
  if ((arg.size() == 2) && (arg[1].asString().toUpper() == "SIGNED"))
    return ArrayVector(VectorOp<OpBin2Int>(arg[0].toClass(Int32),1,
					   arg[0].dimensions().lastNotOne()-1));
  else
    return ArrayVector(VectorOp<OpBin2Int>(arg[0].toClass(UInt32),1,
					   arg[0].dimensions().lastNotOne()-1));
}

