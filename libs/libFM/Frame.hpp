#ifndef __Frame_hpp__
#define __Frame_hpp__

#include "Object.hpp"
#include "FMLib.hpp"
#include "ThreadContext.hpp"

namespace FM
{
  class Frame
  {
  public:
    FMString _name;
    Object _sym_names;
    Object _vars;
    Object _addrs;
    ThreadContext *_ctxt;
    bool _closed;
    int _reg_offset;
  public:
    Frame(ThreadContext *ctxt);
    bool defines(const FMString &name);
    int getAddress(const FMString &name);
    int allocateVariable(const FMString &name);
    void setVariableSlow(const FMString &name, const Object &value);
  };
};

#endif