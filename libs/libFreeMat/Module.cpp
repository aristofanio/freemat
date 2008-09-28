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

#include "DynLib.hpp"
#include "Module.hpp"
#include "FunctionDef.hpp"
#include "Interpreter.hpp"
#include "Exception.hpp"
#include "Context.hpp"
#include "Parser.hpp"
#include "PathSearch.hpp"
#include <QDir>

FM::SymbolTable<DynLib*> libPointers;
StringVector DynamicFunctions;

void ClearLibs(Interpreter* eval) {
  StringVector libnames(libPointers.getCompletions(""));
  for (int i=0;i<libnames.size();i++) {
    DynLib **ptr = libPointers.findSymbol(libnames[i]);
    libPointers.deleteSymbol(libnames[i]);
    delete *ptr;
  }
  for (int i=0;i<DynamicFunctions.size();i++) {
    eval->getContext()->deleteFunction(DynamicFunctions[i]);
  }
  DynamicFunctions.clear();
}

//!
//@Module LOADLIB Load Library Function
//@@Section EXTERNAL
//@@Usage
//The @|loadlib| function allows a function in an external library
//to be added to FreeMat dynamically.  This interface is generally
//to be used as last resort, as the form of the function being called
//is assumed to match the internal implementation.  In short, this
//is not the interface mechanism of choice.  For all but very complicated
//functions, the @|import| function is the preferred approach. Thus,
//only a very brief summary of it is presented here.  The syntax
//for @|loadlib| is
//@[
//  loadlib(libfile, symbolname, functionname, nargin, nargout)
//@]
//where @|libfile| is the complete path to the library to use, @|symbolname|
//is the name of the symbol in the library, @|functionname| is the name
//of the function after it is imported into FreeMat (this is optional, it
//defaults to the @|symbolname|), @|nargin| is the number of input arguments
//(defaults to 0), and @|nargout| is the number of output arguments (defaults
//to 0).  If the number of (input or output) arguments is variable then
//set the corresponding argument to @|-1|.
//@@Signature
//sfunction loadlib LoadLibFunction
//inputs libfile symbolname functionname nargin nargout
//outputs none
//!

ArrayVector LoadLibFunction(int c_nargout,const ArrayVector& narg,
			    Interpreter* eval) {
  QString libfile;
  QString symbolName;
  QString funcName;
  int nargin;
  int nargout;
  ArrayVector arg(narg);

  if (arg.size() < 2) 
    throw Exception("Must supply at least the library file and symbol name");
  libfile = arg[0].asString();
  symbolName = arg[1].asString();
  if (arg.size() < 5)
    nargout = 0;
  else
    nargout = (int) arg[4].asInteger();
  if (arg.size() < 4)
    nargin = 0;
  else
    nargin = (int) arg[3].asInteger();
  if (arg.size() < 3)
    funcName = symbolName;
  else
    funcName = arg[2].asString();
  void *func;
  DynLib *lib = new DynLib(libfile);
  func = lib->GetSymbol(symbolName);
  BuiltInFunctionDef *fdef = new BuiltInFunctionDef;
  fdef->retCount = nargout;
  fdef->argCount = nargin;
  fdef->name = funcName;
  fdef->fptr = (BuiltInFuncPtr) func;
  eval->getContext()->insertFunction(fdef,false);
  DynamicFunctions.push_back(fdef->name);
  return ArrayVector();
}
  
void skipWS(const char* &cp) {
  while (*cp == ' ' || *cp == '\t' || *cp == '\n')
    cp++;
}
  
const char* matchTest(const char* &cp, const char* tmplate) {
  if (strncmp(cp,tmplate,strlen(tmplate)) == 0) {
    cp += strlen(tmplate);
    return tmplate;
  } else 
    return NULL;
}

const char* parseTypeName(const char* &cp) {
  const char* rp;
  skipWS(cp);
  rp = matchTest(cp,"int8");
  if (rp) return rp;
  rp = matchTest(cp,"uint8");
  if (rp) return rp;
  rp = matchTest(cp,"int16");
  if (rp) return rp;
  rp = matchTest(cp,"uint16");
  if (rp) return rp;
  rp = matchTest(cp,"int32");
  if (rp) return rp;
  rp = matchTest(cp,"uint32");
  if (rp) return rp;
  rp = matchTest(cp,"float");
  if (rp) return rp;
  rp = matchTest(cp,"complex");
  if (rp) return rp;
  rp = matchTest(cp,"double");
  if (rp) return rp;
  rp = matchTest(cp,"dcomplex");
  if (rp) return rp;
  rp = matchTest(cp,"string");
  if (rp) return rp;
  return NULL;
}

char* parseArgumentName(const char* &cp) {
  bool byRef;
  const char *rp;
  char *op;
  int identLength;
  skipWS(cp);
  byRef = false;
  if (*cp == '&') {
    byRef = true;
    cp++;
  }
  skipWS(cp);
  if (!isalpha(*cp))
    throw Exception(QString("malformed import function prototype") + 
		    " - error starting at " + cp);
  rp = cp;
  cp++;
  while (isalnum(*cp) || (*cp == '_'))
    cp++; 
  identLength = (cp - rp);
  if (byRef) {
    op = (char*) malloc(identLength+2);
    op[0] = '&';
    op[identLength+1] = 0;
    memcpy(op+1,rp,identLength);
  } else {
    op = (char*) malloc(identLength+1);
    op[identLength] = 0;
    memcpy(op,rp,identLength);
  }
  return op;
}

char* parseBoundsCheck(const char* &cp) {
  int bracketDepth;
  if (*cp != '[') return NULL;
  cp++;
  bracketDepth = 1;
  const char *rp;
  rp = cp;
  while ((bracketDepth > 0) && (*cp != 0)) {
    if (*cp == '[') bracketDepth++;
    if (*cp == ']') bracketDepth--;
    cp++;
  }
  if (bracketDepth > 0)
    throw Exception(QString("malformed bounds check - error starting at ") + 
		    cp);
  char *op;
  int bcLength;
  bcLength = (cp - rp);
  op = (char*) malloc(bcLength+1);
  memcpy(op,rp,bcLength-1);
  op[bcLength-1] = '\n';
  op[bcLength] = 0;
  return op;
}

//!
//@Module IMPORT Foreign Function Import
//@@Section EXTERNAL
//@@Usage
//The import function allows you to call functions that are compiled into
//shared libraries, as if they were FreeMat functions. The usage is
//@[
//  import(libraryname,symbol,function,return,arguments)
//@]
//The argument @|libraryname| is the name of the library (as a string)
//to import the function from.  The second argument @|symbol| (also
//a string), is the name of the symbol to import from the library.  The
//third argument @|function| is the the name of the function after its
//been imported into Freemat.  The fourth argument is a string that
//specifies the return type of the function. It can take on one of the 
//following types:
//\begin{itemize}
//\item 'uint8' for an unsigned, 8-bit integer.
//\item 'int8' for a signed, 8-bit integer.
//\item 'uint16' an unsigned, 16-bit  integer.
//\item 'int16' a signed, 16-bit integer.
//\item 'uint32' for an unsigned, 32-bit integer.
//\item 'int32' for a signed, 32-bit integer.
//\item 'single' for a 32-bit floating point.
//\item 'double' for a 64-bit floating point.
//\item 'void' for no return type.
//\end{itemize}
//The fourth argument is more complicated.  It encodes the arguments of the
//imported function using a special syntax.  In general, the argument list
//is a string consisting of entries of the form:
//
//@[
//  type[optional bounds check] {optional &}name
//@]
//
//Here is a list of various scenarios (expressed in 'C'), and the corresponding
//entries, along with snippets of code.
//
//\emph{Scalar variable passed by value:}
//Suppose a function is defined in the library as
//@[
//  int fooFunction(float t),
//@]
//i.e., it takes a scalar value (or a string) that is passed by value.  Then
//the corresponding argument string would be
//@[
//  'float t'
//@]
//For a C-string, which corresponds to a function prototype of
//@[
//  int fooFunction(const char *t),
//@]
//the corresponding argument string would be
//@[
//  'string t'
//@]
//Other types are as listed above.  Note that FreeMat will automatically
//promote the type of scalar variables to the type expected by the @|C|
//function.  For example, if we call a function expecting a @|float|
//with a @|double| or @|int16| argument, then FreeMat will automatically
//apply type promotion rules prior to calling the function.
//
//\emph{Scalar variable passed by reference:}
//Suppose a function is defined in the library as
//@[
//  int fooFunction(float *t),
//@]
//i.e., it takes a scalar value (or a string) that is passed as a pointer.  Then
//the corresponding argument string would be
//@[
//  'float &t'
//@]
//If the function @|fooFunction| modifies @|t|, then the argument
//passed in FreeMat will also be modified.
//
//\emph{Array variable passed by value:}
//In @|C|, it is impossible to distinguish an array being passed from
//a simple pointer being passed.  More often than not, another argument
//indicates the length of the array.  FreeMat has the ability to perform
//bounds-checking on array values.  For example, suppose we have a function
//of the form
//@[
//  int sum_onehundred_ints(int *t),
//@]
//where @|sum_onehundred_ints| assumes that @|t| is a length @|100| vector. 
//Then the corresponding FreeMat argument is
//@[
//  'float32[100] t'.
//@]
//Note that because the argument is marked as not being passed by reference,
//that if @|sub_onehundred_ints| modifies the array @|t|, this
//will not affect the FreeMat argument.  Note that the bounds-check expression
//can be any legal scalar expression that evaluates to an integer, and can be
//a function of the arguments.  For example to pass a square $N \times N$ 
//matrix to the following function:
//@[
//  float determinantmatrix(int N, float *A),
//@]
//we can use the following argument to @|import|:
//@[
//  'int32 N, float[N*N] t'.
//@]
//
//\emph{Array variable passed by reference:}
//If the function in @|C| modifies an array, and we wish this to be
//reflected in the FreeMat side, we must pass that argument by reference.
//Hence, consider the following hypothetical function that squares the
//elements of an array (functionally equivalent to $x.^2$):
//@[
//  void squarearray(int N, float *A)
//@]
//we can use the following argument to @|import|:
//@[
//  'int32 N, float[N] &A'.
//@]
//Note that to avoid problems with memory allocation, external functions
//are not allowed to return pointers.  As a result, as a general operating
//mechanism, the FreeMat code must allocate the proper arrays, and then
//pass them by reference to the external function.
//
//@@Example
//Here is a complete example.  We have a @|C| function that adds
//two float vectors of the same length, and stores the result in a third array 
//that is modified by the function.  First, the @|C| code:
//@{ addArrays.c
//void addArrays(int N, float *a, float *b, float *c) {
//  int i;
// 
//  for (i=0;i<N;i++)
//   c[i] = a[i] + b[i];
//}
//@}
//We then compile this into a dynamic library, say, @|add.so|.  The import 
//command would then be:
//@[
//  import('add.so','addArrays','addArrays','void', ...
//         'int32 N, float[N] a, float[N] b, float[N] &c');
//@]
//We could then exercise the function exactly as if it had been written
//in FreeMat.  The following only works on systems using the GNU
//C Compiler:
//@<
//if (strcmp(computer,'MAC')) system('gcc -bundle -flat_namespace -undefined suppress -o add.so addArrays.c'); end;
//if (~strcmp(computer,'MAC')) system('gcc -shared -fPIC -o add.so addArrays.c'); end;
//import('add.so','addArrays','addArrays','void','int32 N, float[N] a, float[N] b, float[N] &c');
//a = [3,2,3,1];
//b = [5,6,0,2]; 
//c = [0,0,0,0];
//addArrays(length(a),a,b,c)
//c
//@>
//@@Signature
//sfunction import ImportFunction
//inputs libraryname symbol function returntype arguments
//outputs none 
//!

static inline bool issep(QChar t) {
  return ((t=='/') || (t=='\\'));
}

ArrayVector ImportFunction(int nargout, const ArrayVector& arg, 
			   Interpreter* eval)  {
#ifdef HAVE_AVCALL
  QString libfile;
  QString symbolname;
  QString funcname;
  QString rettype;
  QString arglist;

  PathSearcher psearch(eval->getPath());

  QString libfullpath;

  if (arg.size() < 5)
    throw Exception(QString("import requires 5 arguments:") + 
		    "library name, symbol name, imported function name" +
		    "return type, argument list");
  libfile = arg[0].asString();
  libfullpath = psearch.ResolvePath(libfile);
  QString current(QDir::currentPath());
  // Prepend the current working directory... ugly, but necessary
#ifdef WIN32
  if (!(issep(libfullpath[0]) || ((libfullpath[1] == ':') && 
				  issep(libfullpath[2]))))
    libfullpath = current + "/" + libfullpath;
#else
  if (!issep(libfullpath[0]))
    libfullpath = current + "/" + libfullpath;
#endif
  symbolname = arg[1].asString();
  funcname = arg[2].asString();
  rettype = arg[3].asString();
  arglist = arg[4].asString();
  void *func;
  DynLib *lib, **ptr;
  ptr = libPointers.findSymbol(libfullpath);
  if (!ptr) {
    lib = new DynLib(libfullpath);
    libPointers.insertSymbol(libfullpath,lib);
  } else
    lib = *ptr;
  func = lib->GetSymbol(symbolname);
  StringVector types;
  StringVector arguments;
  CodeList checks;
  /**
   * Parse the arglist...
   */
  const char *cp;
  cp = qPrintable(arglist);

  while (*cp != 0) {
    /**
     * Parse off the typename
     */
    const char *tn;
    tn = parseTypeName(cp);
    if (tn == NULL) 
      throw Exception(QString("illegal syntax in function") + 
		      QString(" prototype (argument list) - ") + 
		      QString("expecting a valid type name"));
    types.push_back(tn);
    char *bc = parseBoundsCheck(cp);
    if (bc != NULL) {
      checks.push_back(ParseExpressionString(bc));
      free(bc);
    } else
      checks.push_back(CodeBlock(new Tree));
    char *ar;
    ar = parseArgumentName(cp);
    arguments.push_back(ar);
    free(ar);
    if (*cp != 0) {
      if (*cp != ',') throw Exception("expecting a ',' between arugments");
      cp++;
    }
  }
  ImportedFunctionDef *fptr = new ImportedFunctionDef((void (*)())func,
						      types,
						      arguments,
						      checks,
						      rettype);
  fptr->name = funcname;
  eval->getContext()->insertFunction(fptr,false);
  DynamicFunctions.push_back(fptr->name);
  return ArrayVector();
#else
  throw Exception("Support for the import command requires that the avcall library be installed.  FreeMat was compiled without this library being available, and hence imported functions are unavailable.  To enable imported commands, please install avcall and recompile FreeMat.");
#endif
}
  