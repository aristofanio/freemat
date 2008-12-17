
# include checks
include(CheckIncludeFile)
check_include_file(argz.h HAVE_ARGZ_H)
check_include_file(assert.h HAVE_ASSERT_H)
check_include_file(dirent.h HAVE_DIRENT_H)
check_include_file(dl.h HAVE_DL_H)
check_include_file(dld.h HAVE_DLD_H)
check_include_file(dlfcn.h HAVE_DLFCN_H)
check_include_file(errno.h HAVE_ERRNO_H)
check_include_file(execinfo.h HAVE_EXECINFO_H)
check_include_file(fcntl.h HAVE_FCNTL_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(link.h HAVE_LINK_H)
check_include_file(malloc.h HAVE_MALLOC_H)
check_include_file(malloc/malloc.h HAVE_MALLOC_MALLOC_H)
check_include_file(memory.h HAVE_MEMORY_H)
check_include_file(ndir.h HAVE_NDIR_H)
check_include_file(pthread.h HAVE_PTHREAD_H)
check_include_file(setjmp.h HAVE_SETJMP_H)
check_include_file(signal.h HAVE_SIGNAL_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdio.h HAVE_STDIO_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(sys/dir.h HAVE_SYS_DIR_H)
check_include_file(sys/dl.h HAVE_SYS_DL_H)
check_include_file(sys/mman.h HAVE_SYS_MMAN_H)
check_include_file(sys/ndir.h HAVE_SYS_NDIR_H)
check_include_file(sys/param.h HAVE_SYS_PARAM_H)
check_include_file(sys/resource.h HAVE_SYS_RESOURCE_H)
check_include_file(sys/stat.h HAVE_SYS_STAT_H)
check_include_file(sys/time.h HAVE_SYS_TIME_H)
check_include_file(sys/types.h HAVE_SYS_TYPES_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_include_file(utime.h HAVE_UTIME_H)

# function checks
include(CheckSymbolExists)
check_symbol_exists(getpagesize unistd.h HAVE_GETPAGESIZE)
check_symbol_exists(getrusage sys/resource.h HAVE_GETRUSAGE)
check_symbol_exists(setrlimit sys/resource.h HAVE_SETRLIMIT)
check_symbol_exists(isinf cmath HAVE_ISINF_IN_CMATH)
check_symbol_exists(isinf math.h HAVE_ISINF_IN_MATH_H)
check_symbol_exists(isnan cmath HAVE_ISNAN_IN_CMATH)
check_symbol_exists(isnan math.h HAVE_ISNAN_IN_MATH_H)
check_symbol_exists(mallinfo malloc.h HAVE_MALLINFO)
check_symbol_exists(pthread_mutex_lock pthread.h HAVE_PTHREAD_MUTEX_LOCK)

if( MINGW )
  # tbi: Comprobar que existen las librerias:
  set(HAVE_LIBIMAGEHLP 1)
  set(HAVE_LIBPSAPI 1)
  #   include(CheckLibraryExists)
  #   CHECK_LIBRARY_EXISTS(imagehlp ??? . HAVE_LIBIMAGEHLP)
endif( MINGW )

# Classes
include(CheckCxxHashmap)
include(CheckCxxHashset)
check_hashmap()
check_hashset()

# FIXME: Signal handler return type, currently hardcoded to 'void'
set(RETSIGTYPE void)

# Disable multithreading for now
set(ENABLE_THREADS 0)

configure_file(
  ${LLVM_MAIN_INCLUDE_DIR}/Config/config.h.cmake
  ${LLVM_BINARY_DIR}/include/llvm/Config/config.h
  )

configure_file(
  ${LLVM_MAIN_INCLUDE_DIR}/ADT/iterator.cmake
  ${LLVM_BINARY_DIR}/include/llvm/ADT/iterator.h
  )

configure_file(
  ${LLVM_MAIN_INCLUDE_DIR}/Support/DataTypes.h.cmake
  ${LLVM_BINARY_DIR}/include/llvm/Support/DataTypes.h
  )

configure_file(
  ${LLVM_MAIN_INCLUDE_DIR}/ADT/hash_map.cmake
  ${LLVM_BINARY_DIR}/include/llvm/ADT/hash_map.h
  )

configure_file(
  ${LLVM_MAIN_INCLUDE_DIR}/ADT/hash_set.cmake
  ${LLVM_BINARY_DIR}/include/llvm/ADT/hash_set.h
  )