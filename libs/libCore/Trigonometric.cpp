/*
 * Copyright (c) 2002-2006 Samit Basu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "Core.hpp"
#include "Exception.hpp"
#include "Array.hpp"
#include <math.h>
#include "Utils.hpp"
#include "IEEEFP.hpp"
#include "Operators.hpp"
#include "Complex.hpp"

//!
//@Module COS Trigonometric Cosine Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|cos| function for its argument.  The general
//syntax for its use is
//@[
//  y = cos(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|cos| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|cos| function is defined for all real
//valued arguments @|x| by the infinite summation
//\[
//  \cos x \equiv \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n}}{(2n)!}.
//\]
//For complex valued arguments @|z|, the cosine is computed via
//\[
//  \cos z \equiv \cos \Re z \cosh \Im z - \sin \Re z
//  \sinh \Im z.
//\]
//@@Example
//The following piece of code plots the real-valued @|cos(2 pi x)|
//function over one period of @|[0,1]|:
//@<
//x = linspace(0,1);
//plot(x,cos(2*pi*x))
//mprint('cosplot');
//@>
//@figure cosplot
//@@Signature
//function cos CosFunction
//inputs x
//outputs y
//!

struct OpCos {
  static inline float func(float x) {return cosf(x);}
  static inline double func(double x) {return cos(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    yr = cosf(xr)*coshf(xi);
    yi = -sinf(xr)*sinhf(xi);
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    yr = cos(xr)*cosh(xi);
    yi = -sin(xr)*sinh(xi);
  }
};

ArrayVector CosFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Cosine Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpCos>(arg[0]));
}

//!
//@Module SIN Trigonometric Sine Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|sin| function for its argument.  The general
//syntax for its use is
//@[
//  y = sin(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|sin| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|sin| function is defined for all real
//valued arguments @|x| by the infinite summation
//\[
//  \sin x \equiv \sum_{n=1}^{\infty} \frac{(-1)^{n-1} x^{2n-1}}{(2n-1)!}.
//\]
//For complex valued arguments @|z|, the sine is computed via
//\[
//  \sin z \equiv \sin \Re z \cosh \Im z - i \cos \Re z
//  \sinh \Im z.
//\]
//@@Example
//The following piece of code plots the real-valued @|sin(2 pi x)|
//function over one period of @|[0,1]|:
//@<
//x = linspace(0,1);
//plot(x,sin(2*pi*x))
//mprint('sinplot')
//@>
//@figure sinplot
//@@Signature 
//function sin SinFunction
//inputs x
//outputs y
//!

struct OpSin {
  static inline float func(float x) {return sinf(x);}
  static inline double func(double x) {return sin(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    yr = sinf(xr)*coshf(xi);
    yi = cosf(xr)*sinhf(xi);
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    yr = sin(xr)*cosh(xi);
    yi = cosf(xr)*sinh(xi);
  }
};

ArrayVector SinFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Sin Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpSin>(arg[0]));
}

//!
//@Module TAN Trigonometric Tangent Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|tan| function for its argument.  The general
//syntax for its use is
//@[
//  y = tan(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|tan| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|tan| function is defined for all real
//valued arguments @|x| by the infinite summation
//\[
//  \tan x \equiv x + \frac{x^3}{3} + \frac{2x^5}{15} + \cdots,
//\]
//or alternately by the ratio
//\[
//  \tan x \equiv \frac{\sin x}{\cos x}
//\]
//For complex valued arguments @|z|, the tangent is computed via
//\[
//  \tan z \equiv \frac{\sin 2 \Re z + i \sinh 2 \Im z}
//                     {\cos 2 \Re z + \cosh 2 \Im z}.
//\]
//@@Example
//The following piece of code plots the real-valued @|tan(x)|
//function over the interval @|[-1,1]|:
//@<
//t = linspace(-1,1);
//plot(t,tan(t))
//mprint('tanplot');
//@>
//@figure tanplot
//@@Signature
//function tan TanFunction
//inputs x
//outputs y
//!

struct OpTan {
  static inline float func(float x) {return tanf(x);}
  static inline double func(double x) {return tan(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    yr = sinf(xr)/(cosf(xr)+coshf(xi));
    yi = sinhf(xi)/(cosf(xr)+coshf(xi));
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    yr = sin(xr)/(cos(xr)+cosh(xi));
    yi = sinh(xi)/(cos(xr)+cosh(xi));
  }
};

ArrayVector TanFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Tangent Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpTan>(arg[0]));
}

//!
//@Module CSC Trigonometric Cosecant Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|csc| function for its argument.  The general
//syntax for its use is
//@[
//  y = csc(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|csc| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|csc| function is defined for all arguments
//as
//\[
//   \csc x \equiv \frac{1}{\sin x}.
//\]
//@@Example
//The following piece of code plots the real-valued @|csc(2 pi x)|
//function over the interval of @|[-1,1]|:
//@<
//t = linspace(-1,1,1000);
//plot(t,csc(2*pi*t))
//axis([-1,1,-10,10]);
//mprint('cscplot');
//@>
//@figure cscplot
//@@Signature
//function csc CscFunction
//inputs x
//outputs y
//!

struct OpCsc {
  static inline float func(float x) {return 1.0f/sinf(x);}
  static inline double func(double x) {return 1.0/sin(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    float zr, zi;
    OpSin::func(xr,xi,zr,zi);
    complex_recip(zr,zi,yr,yi);
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    double zr, zi;
    OpSin::func(xr,xi,zr,zi);
    complex_recip(zr,zi,yr,yi);
  }
};

ArrayVector CscFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Cosecant Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpCsc>(arg[0]));
}

//!
//@Module SEC Trigonometric Secant Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|sec| function for its argument.  The general
//syntax for its use is
//@[
//  y = sec(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|sec| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|sec| function is defined for all arguments
//as
//\[
//   \sec x \equiv \frac{1}{\cos x}.
//\]
//@@Example
//The following piece of code plots the real-valued @|sec(2 pi x)|
//function over the interval of @|[-1,1]|:
//@<
//t = linspace(-1,1,1000);
//plot(t,sec(2*pi*t))
//axis([-1,1,-10,10]);
//mprint('secplot');
//@>
//@figure secplot
//@@Signature
//function sec SecFunction
//inputs x
//outputs y
//!

struct OpSec {
  static inline float func(float x) {return 1.0f/cosf(x);}
  static inline double func(double x) {return 1.0/cos(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    float zr, zi;
    OpCos::func(xr,xi,zr,zi);
    complex_recip(zr,zi,yr,yi);
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    double zr, zi;
    OpCos::func(xr,xi,zr,zi);
    complex_recip(zr,zi,yr,yi);
  }
};

ArrayVector SecFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Secant Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpSec>(arg[0]));
}

//!
//@Module COT Trigonometric Cotangent Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|cot| function for its argument.  The general
//syntax for its use is
//@[
//  y = cot(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|cot| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|cot| function is defined for all 
//arguments @|x| as
//\[
//  \cot x \equiv \frac{\cos x}{\sin x}
//\]
//For complex valued arguments @|z|, the cotangent is computed via
//\[
//  \cot z \equiv \frac{\cos 2 \Re z + \cosh 2 \Im z}{\sin 2 \Re z + 
//  i \sinh 2 \Im z}.
//\]
//@@Example
//The following piece of code plots the real-valued @|cot(x)|
//function over the interval @|[-1,1]|:
//@<
//t = linspace(-1,1);
//plot(t,cot(t))
//mprint('cotplot');
//@>
//@figure cotplot
//@@Signature
//function cot CotFunction
//inputs x
//outputs y
//!

struct OpCot {
  static inline float func(float x) {return 1.0f/tanf(x);}
  static inline double func(double x) {return 1.0/tan(x);}
  static inline void func(float xr, float xi, float &yr, float &yi) {
    yr = sinf(xr)/(-cosf(xr)+coshf(xi));
    yi = -sinhf(xi)/(-cosf(xr)+coshf(xi));
  }
  static inline void func(double xr, double xi, double &yr, double &yi) {
    yr = sin(xr)/(-cos(xr)+cosh(xi));
    yi = -sinh(xi)/(-cos(xr)+cosh(xi));
  }
};

ArrayVector CotFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Cotangent Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpCot>(arg[0]));
}

//!
//@Module ACOS Inverse Trigonometric Arccosine Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|acos| function for its argument.  The general
//syntax for its use is
//@[
//  y = acos(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|acos| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|acos| function is defined for all 
//arguments @|x| as
//\[
// \mathrm{acos} x \equiv \frac{pi}{2} + i \log \left(i x + 
//  \sqrt{1-x^2}\right).
//\]
//For real valued variables @|x| in the range @|[-1,1]|, the function is
//computed directly using the standard C library's numerical @|acos|
//function. For both real and complex arguments @|x|, note that generally
//\[
//  \mathrm{acos}(\cos(x)) \neq x,
//\] due to the periodicity of @|cos(x)|.
//@@Example
//The following code demonstates the @|acos| function over the range 
//@|[-1,1]|.
//@<
//t = linspace(-1,1);
//plot(t,acos(t))
//mprint('acosplot');
//@>
//@figure acosplot
//@@Signature
//function acos ArccosFunction
//inputs x
//outputs y
//!

struct OpAcos {
  static inline float func(float x) {return acosf(x);}
  static inline double func(double x) {return acos(x);}
  template <typename T>
  static inline void func(T xr, T xi, T &yr, T &yi) {
    T xsq_real, xsq_imag;
    // Compute x^2
    complex_square(xr,xi,xsq_real,xsq_imag);
    // Compute 1-x^2
    xsq_real = 1.0 - xsq_real;
    xsq_imag = -xsq_imag;
    T xrt_real, xrt_imag;
    // Compute sqrt(1-x^2)
    complex_sqrt(xsq_real,xsq_imag,xrt_real,xrt_imag);
    // Add i*x = i*(a+b*i) = -b+i*a
    xrt_real -= xi;
    xrt_imag += xr;
    // Take the complex log
    T xlg_real, xlg_imag;
    complex_log(xrt_real,xrt_imag,xlg_real,xlg_imag);
    // Answer = pi/2
    yr = 2.0*atan(1.0) - xlg_imag;
    yi = xlg_real;
  }
};

ArrayVector ArccosFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Arccosine Function takes exactly one argument");
  Array input(arg[0]);
  if (input.allReal() && (ArrayRange(input) > 1))
    input.forceComplex();
  return ArrayVector(UnaryOp<OpAcos>(input));
}

//!
//@Module ASIN Inverse Trigonometric Arcsine Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|asin| function for its argument.  The general
//syntax for its use is
//@[
//  y = asin(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|asin| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|asin| function is defined for all 
//arguments @|x| as
//\[ 
//   \mathrm{asin} x \equiv - i \log \left(i x + 
//   \sqrt{1-x^2}\right).
//\]
//For real valued variables @|x| in the range @|[-1,1]|, the function is
//computed directly using the standard C library's numerical @|asin|
//function. For both real and complex arguments @|x|, note that generally
//\[
//   \mathrm{asin}(\sin(x)) \neq x,
//\] 
//due to the periodicity of @|sin(x)|.
//@@Example
//The following code demonstates the @|asin| function over the range 
//@|[-1,1]|.
//@<
//t = linspace(-1,1);
//plot(t,asin(t))
//mprint('asinplot');
//@>
//@figure asinplot
//@@Signature
//function asin ArcsinFunction
//inputs x
//outputs y
//!

struct OpAsin {
  static inline float func(float x) {return asinf(x);}
  static inline double func(double x) {return asin(x);}
  template <typename T>
  static inline void func(T xr, T xi, T &yr, T &yi) {
    T xsq_real, xsq_imag;
    // Compute x^2
    complex_square(xr,xi,xsq_real,xsq_imag);
    // Compute 1-x^2
    xsq_real = 1.0 - xsq_real;
    xsq_imag = -xsq_imag;
    T xrt_real, xrt_imag;
    // Compute sqrt(1-x^2)
    complex_sqrt(xsq_real,xsq_imag,xrt_real,xrt_imag);
    // Add i*x = i*(a+b*i) = -b+i*a
    xrt_real -= xi;
    xrt_imag += xr;
    // Take the complex log
    T xlg_real, xlg_imag;
    complex_log(xrt_real,xrt_imag,xlg_real,xlg_imag);
    // Answer = pi/2
    yr = xlg_imag;
    yi = -xlg_real;
  }
};

ArrayVector ArcsinFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Arcsine Function takes exactly one argument");
  Array input(arg[0]);
  if (input.allReal() && (ArrayRange(input) > 1))
    input.forceComplex();
  return ArrayVector(UnaryOp<OpAsin>(input));
}

//!
//@Module ATAN Inverse Trigonometric Arctangent Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|atan| function for its argument.  The general
//syntax for its use is
//@[
//  y = atan(x)
//@]
//where @|x| is an @|n|-dimensional array of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|atan| function.  Output @|y| is of the
//same size and type as the input @|x|, (unless @|x| is an
//integer, in which case @|y| is a @|double| type).  
//@@Function Internals
//Mathematically, the @|atan| function is defined for all 
//arguments @|x| as
//\[ 
//   \mathrm{atan} x \equiv \frac{i}{2}\left(\log(1-i x) - \log(i x + 1)\right).
//\]
//For real valued variables @|x|, the function is computed directly using 
//the standard C library's numerical @|atan| function. For both 
//real and complex arguments @|x|, note that generally
//
//\[
//    \mathrm{atan}(\tan(x)) \neq x,
//\]
// due to the periodicity of @|tan(x)|.
//@@Example
//The following code demonstates the @|atan| function over the range 
//@|[-1,1]|.
//@<
//t = linspace(-1,1);
//plot(t,atan(t))
//mprint('atanplot');
//@>
//@figure atanplot
//@@Signature
//function atan ArcTanFunction
//inputs x
//outputs y
//!

struct OpAtan {
  static inline float func(float x) {return atanf(x);}
  static inline double func(double x) {return atan(x);}
  template <typename T>
  static inline void func(T xr, T xi, T &yr, T&yi) {
    T a_real, a_imag;
    T b_real, b_imag;
    complex_log(1 + xi,-xr,a_real,a_imag);
    complex_log(1 - xi,xr,b_real,b_imag);
    yr = -0.5*(a_imag-b_imag);
    yi = 0.5*(a_real-b_real);
  }
};

ArrayVector ArcTanFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() != 1)
    throw Exception("Arctan Function takes exactly one argument");
  return ArrayVector(UnaryOp<OpAtan>(arg[0]));
}

//!
//@Module ATAN2 Inverse Trigonometric 4-Quadrant Arctangent Function
//@@Section MATHFUNCTIONS
//@@Usage
//Computes the @|atan2| function for its argument.  The general
//syntax for its use is
//@[
//  z = atan2(y,x)
//@]
//where @|x| and @|y| are @|n|-dimensional arrays of numerical type.
//Integer types are promoted to the @|double| type prior to
//calculation of the @|atan2| function. The size of the output depends
//on the size of @|x| and @|y|.  If @|x| is a scalar, then @|z|
//is the same size as @|y|, and if @|y| is a scalar, then @|z|
//is the same size as @|x|.  The type of the output is equal to the type of
//|y/x|.  
//@@Function Internals
//The function is defined (for real values) to return an 
//angle between @|-pi| and @|pi|.  The signs of @|x| and @|y|
//are used to find the correct quadrant for the solution.  For complex
//arguments, the two-argument arctangent is computed via
//\[
//  \mathrm{atan2}(y,x) \equiv -i \log\left(\frac{x+i y}{\sqrt{x^2+y^2}} \right)
//\]
//For real valued arguments @|x,y|, the function is computed directly using 
//the standard C library's numerical @|atan2| function. For both 
//real and complex arguments @|x|, note that generally
//\[
//  \mathrm{atan2}(\sin(x),\cos(x)) \neq x,
//\]
//due to the periodicities of  @|cos(x)| and @|sin(x)|.
//@@Example
//The following code demonstates the difference between the @|atan2| 
//function and the @|atan| function over the range @|[-pi,pi]|.
//@<
//x = linspace(-pi,pi);
//sx = sin(x); cx = cos(x);
//plot(x,atan(sx./cx),x,atan2(sx,cx))
//mprint('atan2plot');
//@>
//@figure atan2plot
//Note how the two-argument @|atan2| function (green line) 
//correctly ``unwraps'' the phase of the angle, while the @|atan| 
//function (red line) wraps the angle to the interval @|[-\pi/2,\pi/2]|.
//@@Signature
//function atan2 Arctan2Function
//inputs y x
//outputs z
//!

struct OpAtan2 {
  static inline float func(float y, float x) {return atan2f(y,x);}
  static inline double func(double y, double x) {return atan2(y,x);}
  template <typename T>
  static inline void func(T y_real, T y_imag, T x_real, T x_imag, T &z_real, T &z_imag) {
    T a_real, a_imag;
    a_real = x_real - y_imag;
    a_imag = x_imag + y_real;
    // compute x_squared and y_squared
    T xsqr_real, xsqr_imag;
    T ysqr_real, ysqr_imag;
    complex_square(x_real,x_imag,xsqr_real,xsqr_imag);
    complex_square(y_real,y_imag,ysqr_real,ysqr_imag);
    T den_real, den_imag;
    den_real = xsqr_real + ysqr_real;
    den_imag = xsqr_imag + ysqr_imag;
    T den_sqrt_real, den_sqrt_imag;
    complex_sqrt(den_real,den_imag,den_sqrt_real,den_sqrt_imag);
    // compute the log of the numerator
    T log_num_real, log_num_imag;
    complex_log(a_real,a_imag,log_num_real,log_num_imag);
    // compute the log of the denominator
    T log_den_real, log_den_imag;
    complex_log(den_sqrt_real,den_sqrt_imag,log_den_real,log_den_imag);
    // compute the num - den
    log_num_real -= log_den_real;
    log_num_imag -= log_den_imag;
    // compute -i * (c_r + i * c_i) = c_i - i * c_r
    z_real = log_num_imag;
    z_imag = -log_num_real;
  }
};

ArrayVector Arctan2Function(int nargout, const ArrayVector& arg) {
  if (arg.size() != 2)
    throw Exception("Arctan2 Function takes exactly two arguments");
  Array y(arg[0]);
  Array x(arg[1]);
  return ArrayVector(DotOp<OpAtan2>(y,x));
}