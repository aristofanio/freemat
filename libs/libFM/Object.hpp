#ifndef __Object_hpp__
#define __Object_hpp__

#include "Type.hpp"
#include "Tuple.hpp"

namespace FM
{

  // Priority list:
  // double
  // complex
  // single
  // scomplex
  // integer
  // icomplex
  // sparse ?


  // The ArrayBase is really a bare, reference counted data chunk.
  // But unlike most reference counted objects, it doesn't know
  // anything about the type of the data block it has, so it cannot
  // be a true object.
  struct Data {
    ref_t refcnt;
    void *ptr;
  };

  class ObjectBase;

  template <class T>
  class PODArrayType;

  template <class T, bool _objtype>
  class PODType;

  class StringType;


  // Flags like complexity must be carried at this level, since the 
  // type does not indicate complexity.
  const int OBJECT_COMPLEX_FLAG = 4;

  class ObjectBase {
  private:
    ObjectBase();
    ObjectBase& operator=(const ObjectBase& t);
    //! The pointer to the actual data.  Must not be NULL.
    Data *data;
    //! Reference count.  The Object is reference counted,
    //but also contains a reference counting pointer to the
    //underlying data.  This dual level of reference counting
    //seems inelegant, but is required by the need for slicing.
    //Slicing means that one object has an internal (read-only)
    //view into another objects data.
    ref_t refcnt;
    //! Pointer to the base metatype object that contains the 
    //method pointers for the object of interest.
    Type *type;
    //! The offset into the data vector.  This is 
    //used for slicing.
    size_t offset;
    //! The dimensions of the array
    Tuple dims;
    //! The flags for the object
    int flags;
    //! The ultimate capacity of the object.  Allows for expansion
    // without reallocating/copying
    dim_t capacity;
  public:
    ObjectBase(Data* p, Type* _type, size_t _offset, Tuple _dims, int _flags, size_t _capacity) : data(p) {
      data->refcnt++;
      type = _type;
      offset = _offset;
      dims = _dims;
      flags = _flags;
      capacity = _capacity;
      refcnt = 0;
    }
    ObjectBase(const ObjectBase& t) {
      type = t.type;
      refcnt = 0;
      dims = t.dims;
      offset = t.offset;
      data = t.data;
      data->refcnt++;
      flags = t.flags;
      capacity = t.capacity;
    }
    friend class Object;
    friend class Type;
    template <class T>  friend class PODArrayType;
    template <class T, bool _objtype> friend class PODType;
    template <class T> friend class AggregateType;
    friend class DoubleType;
    friend class SingleType;
    friend class StringType;
    friend class StructType;
    friend class ListType;
    //  friend class PODArrayType<double>;
  };


  // Need to add a default constructor for Object that
  // points to a global "Empty" object (maybe with its
  // own type?).
  class Object
  {
    ObjectBase *d;
  public:
    inline Object() : d(0) {}
    inline bool isValid() const {return (d!=0);}
    inline Object(ObjectBase *p) : d(p) {
      if (d) d->refcnt++;
    }
    inline Object(const Object &copy) : d(copy.d) {
      if (d) d->refcnt++;
    }
    inline ~Object() {
      if (d && ((--d->refcnt) == 0))
	d->type->destroyObject(d);
    }
    inline const Tuple& dims() const {
      return d->dims;
    }
    inline Tuple& dims() {
      detach();
      return d->dims;
    }
    inline dim_t rows() const {
      if (!d) return 0;
      return d->dims.rows();
    }
    inline dim_t cols() const {
      if (!d) return 0;
      return d->dims.cols();
    }
    inline bool isEmpty() const {
      if (!d) return false;
      return (elementCount() == 0);
    }
    inline bool isComplex() const {
      if (!d) return false;
      return ((d->flags & OBJECT_COMPLEX_FLAG) != 0);
    }
    inline bool isScalar() const {
      if (!d) return false;
      return (elementCount() == 1);
    }
    inline bool is2D() const {
      if (!d) return false;
      return (d->dims.is2D());
    }
    inline int flags() const {
      if (!d) return 0;
      return d->flags;
    }
    inline FMString description() const {
      if (!d) return FMString("Null");
      return d->type->describe(*this);
    }
    inline dim_t elementCount() const {
      return d->dims.elementCount();
    }
    inline Object asIndex(dim_t max) const {
      return d->type->asIndex(*this,max);
    }
    inline Object asIndexNoBoundsCheck() const {
      return d->type->asIndexNoBoundsCheck(*this);
    }
    inline double asDouble() const {
      return d->type->doubleValue(*this);
    }
    Object& operator=(const Object& copy) {
      if (this == &copy) return *this;
      if (d && ((--d->refcnt) == 0))
	d->type->destroyObject(d);
      d = copy.d;
      if (d) d->refcnt++;
      return *this;
    }
    inline void detach() 
    {
      if (!d) return;
      if (d->refcnt > 1) {
	d = new ObjectBase(*d);
	d->refcnt++;
      }
      if (d->data->refcnt > 1) {
	d->data = d->type->duplicateData(d,d->capacity);
	d->offset = 0;
      }
    }
    inline Type* type() const
    {
      if (!d) 
	throw Exception("Null objects have no type - internal FreeMat error");
      return d->type;
    }
    template <class S>
    inline S* asType() const
    {
      if (!d) 
	throw Exception("Null objects have no type - internal FreeMat error");
      return static_cast<S*>(d->type);
    }
    friend class PODArrayType<double>;
    friend class PODType<double, false>;
    template <class T, bool _objtype> friend class PODType;
    template <class T> friend class AggregateType;
    friend class DoubleType;
    friend class SingleType;
    friend class IndexType;
    friend class Int32Type;
    friend class BoolType;
    friend class StringType;
    friend class StructType;
    friend class ListType;


    bool operator==(const Object& b) const {
      if (type()->code() != b.type()->code()) return false;
      return type()->equals(*this,b);
    }
  };

  inline std::ostream& operator<<(std::ostream &o, const Object &a) {
    o << a.description();
    return o;
  }

  // What we want is to have underlying types for each object.
  //
  // So, A --> typeA
  // and B --> typeB
  //
  // That means that each combination of (A,B) must be handled.
  // However, we can use the left-most 
  //
  // So Add should do something like this:
  //
  // if (B->type()->order() > A->type()->order())
  //   B->type()->dothis(A,B)
  // else
  //   A->type()->dothis(A,B)
  //

  // For the built in objects, we can then ignore order, as all built-in objects
  // have the same precedence.

  const bool RealCase = false;
  const bool ComplexCase = true;

  class ObjectVector : public FMVector<Object> {};


  /* To be added later...
     template <class Op, int IntCode, class IntType>
     Object IntegerType::binop(const Object &a, const Object &b)
     {
     switch (b.type()->code())
     {
     case Double:
     return dispatch_binop<IntType,IntType,double,double,Op>(a,b,a.type());
     case IntCode:
     return dispatch_binop<IntType,IntType,IntType,double,Op>(a,b,a.type());
     default:
     throw Exception("Unsupported type combination of " + a.type()->name() + " and " + b.type()->name());
     }
     }

     template <class Op>
     Object SingleType::binop(const Object &a, const Object &b)
     {
     switch (b.type()->code())
     {
     case Double:
     return dispatch_binop<float,float,double,double,Op>(a,b,a.type());
     case Single:
     return dispatch_binop<float,float,float,float,Op>(a,b,a.type());
     default:
     throw Exception("Unsupported combination of " + a.type()->name() + " and " + b.type()->name());
     }
     }
  */
}

#endif