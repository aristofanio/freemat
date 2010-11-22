#ifndef COMPILER_H_
#define COMPILER_H_

#define __STDC_LIMIT_MACROS
#define __STDC_CONSTANT_MACROS
/*
 *  AlloSphere Research Group / Media Arts & Technology, UCSB, 2009
 */

/*
    Copyright (C) 2006-2008. The Regents of the University of California (REGENTS).
    All Rights Reserved.

    Permission to use, copy, modify, distribute, and distribute modified versions
    of this software and its documentation without fee and without a signed
    licensing agreement, is hereby granted, provided that the above copyright
    notice, the list of contributors, this paragraph and the following two paragraphs
    appear in all copies, modifications, and distributions.

    IN NO EVENT SHALL REGENTS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
    SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING
    OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF REGENTS HAS
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE. THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
    HEREUNDER IS PROVIDED "AS IS". REGENTS HAS  NO OBLIGATION TO PROVIDE
    MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

#include <QtCore/QVector>
#include <QtCore/QString>
#include <QtCore/QSharedPointer>
#include "llvm/Support/MemoryBuffer.h"
/*
    A wrapper around the LLVM/Clang APIs
*/

namespace ClangCompiler {

class JIT;
class ModuleImpl;

typedef QSharedPointer<llvm::MemoryBuffer> LLVMMemSharedPtr;

/*
    Compiler is responsible for compiling, reading, and linking different sources
*/
class Compiler {
public:
    struct Options {
        unsigned CPlusPlus;
        QVector<QString> system_includes;
        QVector<QString> user_includes;
        Options()
            : CPlusPlus(1) {}
    };
    Compiler::Options options;
    QVector<LLVMMemSharedPtr> sources_buffer;

    Compiler();
    ~Compiler();

    /*
        Note: successive compiles/bitcode reads are linked together.
    */
    bool add_source(const QString& code, const QString& name);
    bool compile( void );
    bool readbitcode(std::string path);
    bool writebitcode(std::string path);
    void optimize(std::string flag = "02");

    /*
        discards any code compiled so far.
    */
    void clear();

    /*
        transfers code compiled so far into the JIT engine
        runs any static constructors for this code at this point
        calls clear() to reset this Compiler
    */
    JIT * jit();

    /*
        print module to stdout
    */
    void dump(std::string path);

private:
    friend class ModuleImpl;
    class ModuleImpl * mImpl;
};

/*
    JIT is responsible for retrieving pointers and functions
    from the code registered with the run-time execution engine
*/
class JIT {
private:
    friend class Compiler;
    JIT();
public:
    ~JIT(); // when a JIT is freed, the functions/pointers associated with it are freed to

    // TODO: maybe also offer a per-function optimize here?
    void * getfunctionptr(std::string funcname);
    void * getglobalptr(std::string globalname);
private:
    friend class ModuleImpl;
    class ModuleImpl * mImpl;
};




} // al::
#endif /* COMPILER_H_ */