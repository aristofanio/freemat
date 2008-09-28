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

#include "Array.hpp"
#include "Interpreter.hpp"
#include "Utils.hpp"
#include <stdio.h>
#include "System.hpp"
#include <QtCore>
#include "Algorithms.hpp"

//!
//@Module CD Change Working Directory Function
//@@Section OS
//@@Usage
//Changes the current working directory to the one specified as the argument.  The general syntax for its use is
//@[
//  cd('dirname')
//@]
//but this can also be expressed as
//@[
//  cd 'dirname'
//@]
//or 
//@[
//  cd dirname
//@]
//Examples of all three usages are given below.
//Generally speaking, @|dirname| is any string that would be accepted 
//by the underlying OS as a valid directory name.  For example, on most 
//systems, @|'.'| refers to the current directory, and @|'..'| refers 
//to the parent directory.  Also, depending on the OS, it may be necessary 
//to ``escape'' the directory seperators.  In particular, if directories 
//are seperated with the backwards-slash character @|'\\'|, then the 
//path specification must use double-slashes @|'\\\\'|. Note: to get 
//file-name completion to work at this time, you must use one of the 
//first two forms of the command.
//
//@@Example
//The @|pwd| command returns the current directory location.  First, 
//we use the simplest form of the @|cd| command, in which the directory 
//name argument is given unquoted.
//@<
//pwd
//cd ..
//pwd
//@>
//Next, we use the ``traditional'' form of the function call, using 
//both the parenthesis and a variable to store the quoted string.
//@<
//a = pwd;
//cd(a)
//pwd
//@>
//@@Signature
//sfunction cd ChangeDirFunction
//inputs path
//outputs none
//!
ArrayVector ChangeDirFunction(int nargout, const ArrayVector& arg, Interpreter* eval) {
  if (arg.size() != 1)
    throw Exception("cd function requires exactly one argument");
  if (!QDir::setCurrent(TildeExpand(arg[0].asString())))
    throw Exception("Unable to change to specified directory:" + arg[0].asString());
  eval->rescanPath();
  return ArrayVector();
}

static void TabledOutput(StringVector sysresult, Interpreter* eval) {
  int maxlen = 0;
  // Find the maximal length
  for (int i=0;i<(int)sysresult.size();i++) {
    int ellen(sysresult[i].size());
    maxlen = (maxlen < ellen) ? ellen : maxlen;
  }
  // Calculate the number of columns that fit..
  int outcolumns;
  int termwidth = eval->getTerminalWidth()-1;
  outcolumns = termwidth/(maxlen+1);
  if (outcolumns < 1) outcolumns = 1;
  int colwidth = termwidth/outcolumns;
  int entryCount = 0;
  while (entryCount < (int)sysresult.size()) {
    char buffer[4096];
    sprintf(buffer,"%s",qPrintable(sysresult[entryCount]));
    int wlen;
    wlen = strlen(buffer);
    for (int j=wlen;j<colwidth;j++)
      buffer[j] = ' ';
    buffer[colwidth] = 0;
    eval->outputMessage(buffer);
    entryCount++;
    if (entryCount % outcolumns == 0)
      eval->outputMessage("\n");
  }
  eval->outputMessage("\n");
}

//!
//@Module DIR List Files Function
//@@Section OS
//@@Usage
//In some versions of FreeMat (pre 3.1), the @|dir| function was aliased
//to the @|ls| function.  Starting with version @|3.1|, the @|dir| function
//has been rewritten to provide compatibility with MATLAB.  The general syntax
//for its use is
//@[
//  dir
//@]
//in which case, a listing of the files in the current directory are output to the
//console.  Alternately, you can specify a target via
//@[
//  dir('name')
//@]
//or using the string syntax
//@[
//  dir name
//@]
//If you want to capture the output of the @|dir| command, you can assign the output
//to an array
//@[
//  result = dir('name')
//@]
//(or you can omit @|'name'| to get a directory listing of the current directory.  The
//resulting array @|result| is a structure array containing the fields:
//\begin{itemize}
//   \item @|name| the filename as a string
//   \item @|date| the modification date and time stamp as a string
//   \item @|bytes| the size of the file in bytes as a @|uint64|
//   \item @|isdir| a logical that is @|1| if the file corresponds to a directory.
//\end{itemize}
//Note that @|'name'| can also contain wildcards (e.g., @|dir *.m| to get a listing of
//all FreeMat scripts in the current directory.
//@@Signature
//sfunction dir DirFunction
//inputs name
//outputs array
//!
ArrayVector DirFunction(int nargout, const ArrayVector& arg, Interpreter* eval) {
  // Check for the case that the given name 
  QString dirarg;
  if (arg.size() > 0)
    dirarg = arg[0].asString();
  QDir pdir(QDir::current());
  QFileInfoList foo;
  if (pdir.cd(dirarg))
    foo = pdir.entryInfoList();
  else {
    if (dirarg.lastIndexOf(QDir::separator()) == -1)
      // it must be a pattern
      foo = pdir.entryInfoList(QStringList() << dirarg);
    else {
      // its not a pattern - its a mixed directory and pattern
      // combination.
      int path_length(dirarg.lastIndexOf(QDir::separator()));
      if (pdir.cd(dirarg.left(path_length+1)))
	foo = pdir.entryInfoList(QStringList() << dirarg.right(dirarg.size()-path_length-1));
    }
  }
  if (nargout == 0) {
    StringVector filelist;
    for (int i=0;i<foo.size();i++)
      filelist.push_back(foo[i].fileName());
    TabledOutput(filelist,eval);
  } else {
    // Output is a structure array
    StringVector fileNames;
    StringVector dates;
    ArrayVector bytes;
    ArrayVector isdirs;
    for (int i=0;i<foo.size();i++) {
      fileNames << foo[i].fileName();
      dates << foo[i].lastModified().toString();
      bytes << Array(double(foo[i].size()));
      isdirs << Array(bool(foo[i].isDir()));
    }
    return ArrayVector() << StructConstructor(StringVector() 
					      << "name"
					      << "date"
					      << "bytes"
					      << "isdir",
					      ArrayVector() 
					      << CellArrayFromStringVector(fileNames)
					      << CellArrayFromStringVector(dates)
					      << CellConstructor(bytes)
					      << CellConstructor(isdirs));
  }
  return ArrayVector();
}


//!
//@Module LS List Files Function
//@@Section OS
//@@Usage
//Lists the files in a directory or directories.  The general syntax for its use is
//@[
//  ls('dirname1','dirname2',...,'dirnameN')
//@]
//but this can also be expressed as
//@[
//  ls 'dirname1' 'dirname2' ... 'dirnameN'
//@]
//or 
//@[
//  ls dirname1 dirname2 ... dirnameN
//@]
//For compatibility with some environments, the function @|dir| can also be used instead of @|ls|.  Generally speaking, @|dirname| is any string that would be accepted by the underlying OS as a valid directory name.  For example, on most systems, @|'.'| refers to the current directory, and @|'..'| refers to the parent directory.  Also, depending on the OS, it may be necessary to ``escape'' the directory seperators.  In particular, if directories are seperated with the backwards-slash character @|'\\'|, then the path specification must use double-slashes @|'\\\\'|. Two points worth mentioning about the @|ls| function:
//\begin{itemize}
//  \item To get file-name completion to work at this time, you must use one of the first two forms of the command.
//  \item If you want to capture the output of the @|ls| command, use the @|system| function instead.
//\end{itemize}
//
//@@Example
//First, we use the simplest form of the @|ls| command, in which the directory name argument is given unquoted.
//@<
//ls m*.m
//@>
//Next, we use the ``traditional'' form of the function call, using both the parenthesis and the quoted string.
//@<
//ls('m*.m')
//@>
//In the third version, we use only the quoted string argument without parenthesis.  
//@<
//ls 'm*.m'
//@>
//@@Signature
//sfunction ls ListFilesFunction
//inputs varargin
//outputs none
//!
ArrayVector ListFilesFunction(int nargout, const ArrayVector& arg, Interpreter* eval) {
  StringVector sysresult;
  QString buffer;
  int i;

#ifdef WIN32
  buffer = "dir ";
  for (i=0;i<arg.size();i++)
    buffer += arg[i].asString();
  sysresult = DoSystemCallCaptured(buffer);
  for (i=0;i<sysresult.size();i++) {
    eval->outputMessage(sysresult[i]);
    eval->outputMessage("\n");
  }
#else
  buffer = "ls ";
  for (i=0;i<arg.size();i++) {
    QString fipath(TildeExpand(arg[i].asString()));
    buffer += fipath;
  }
  sysresult = DoSystemCallCaptured(buffer);
  TabledOutput(sysresult,eval);
#endif
  return ArrayVector();
}

//!
//@Module DIRSEP Director Seperator
//@@Section OS
//@@Usage
//Returns the directory seperator character for the current platform.  The 
//general syntax for its use is
//@[
//   y = dirsep
//@]
//This function can be used to build up paths (or see @|fullfile| for another
//way to do this.
//@@Signature
//function dirsep DirSepFunction
//inputs none
//outputs y
//!
ArrayVector DirSepFunction(int nargout, const ArrayVector& arg) {
  return ArrayVector(Array(QString(QDir::separator())));
}

//!
//@Module PWD Print Working Directory Function
//@@Section OS
//@@Usage
//Returns a @|string| describing the current working directory.  The general syntax for its use is
//@[
//  y = pwd
//@]
//
//@@Example
//The @|pwd| function is fairly straightforward.
//@<
//pwd
//@>
//@@Signature
//function pwd PrintWorkingDirectoryFunction
//inputs none
//outputs y
//!
ArrayVector PrintWorkingDirectoryFunction(int nargout, const ArrayVector& arg) {
  return ArrayVector(Array(QDir::currentPath()));
}


//!
//@Module RMDIR Remove Directory
//@@Section OS
//@@Usage
//Deletes a directory.  The general syntax for its use is
//@[
//  rmdir('dirname')
//@]
//which removes the directory @|dirname| if it is empty.  If you
//want to delete the directory and all subdirectories and files
//in it, use the syntax
//@[
//  rmdir('dirname','s')
//@]
//@@Signature
//function rmdir RMDirFunction
//inputs dirname flag
//outputs none
//!
inline void RemoveDirectory(QString dirname) {
  QDir::current().rmdir(dirname);
}

inline void RemoveDirectoryRecursive(QString dirname) {
  QDir dir(dirname);
  dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
  QFileInfoList list = dir.entryInfoList();
  for (int i=0;i<list.size();i++) {
    QFileInfo fileInfo = list.at(i);
    if (fileInfo.isDir())
      RemoveDirectoryRecursive(fileInfo.absoluteFilePath());
    else
      dir.remove(fileInfo.absoluteFilePath());
  }
  QDir::current().rmdir(dirname);
}

ArrayVector RMDirFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() == 0)
    throw Exception("rmdir requires at least one argument (the directory to remove)");
  if (arg.size() == 1)
    RemoveDirectory(arg[0].asString());
  else if (arg.size() == 2) {
    QString arg1 = arg[1].asString();
    if ((arg1 == "s") || (arg1 == "S"))
      RemoveDirectoryRecursive(arg[0].asString());
    else
      throw Exception("rmdir second argment must be a 's' to do a recursive delete");
  }
  return ArrayVector();
}

// See mkdir.m for documentation
//@@Signature
//function mkdir_core MKDirCoreFunction
//inputs dir
//outputs flag
ArrayVector MKDirCoreFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() == 0)
    throw Exception("mkdir requires at least one argument (the directory to create)");
  if (QDir::current().mkpath(arg[0].asString()))
    return ArrayVector(Array(bool(true)));
  else
    return ArrayVector(Array(bool(false)));
}

//!
//@Module FILEPARTS Extract Filename Parts
//@@Section OS
//@@Usage
//The @|fileparts| takes a filename, and returns the path, filename, extension, and
//(for MATLAB-compatibility) an empty version number of the file.  The syntax for its use is
//@[
//    [path,name,extension,version] = fileparts(filename)
//@]
//where @|filename| is a string containing the description of the file, and @|path|
//is the @|path| to the file, 
//@@Signature
//function fileparts FilePartsFunction
//inputs filename
//outputs path name extension version
//!
ArrayVector FilePartsFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() == 0)
    throw Exception("fileparts requires a filename");
  QFileInfo fi(arg[0].asString());
  Array path(fi.path());
  Array name(fi.completeBaseName());
  Array suffix;
  if (fi.suffix().size() > 0)
    suffix = Array("." + fi.suffix());
  else
    suffix = Array(QString(""));
  return ArrayVector() << path
		       << name
		       << suffix
		       << Array(QString(""));
}

//!
//@Module DELETE Delete a File
//@@Section OS
//@@Usage
//Deletes a file.  The general syntax for its use is
//@[
//  delete('filename')
//@]
//or alternately
//@[
//  delete filename
//@]
//which removes the file described by @|filename| which must
//be relative to the current path.
//@@Signature
//function delete DeleteFunction
//inputs filename
//outputs none
//!
ArrayVector DeleteFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() == 0)
    throw Exception("delete requires at least one argument");
  QString filename(arg[0].asString());
  QFileInfo fname(filename);
  if (fname.exists())
    fname.dir().remove(fname.fileName());
  else {
    QFileInfoList foo(QDir::current().entryInfoList(QStringList() << filename));
    for (int i=0;i<foo.size();i++)
      foo[i].dir().remove(foo[i].fileName());
  }
  return ArrayVector();
}

//!
//@Module COPYFILE Copy Files
//@@Section OS
//@@Usage
//Copies a file or files from one location to another.  There are 
//several syntaxes for this function that are acceptable:
//@[
//   copyfile(file_in,file_out)
//@]
//copies the file from @|file_in| to @|file_out|.  Also, the second
//argument can be a directory name:
//@[
//   copyfile(file_in,directory_out)
//@]
//in which case @|file_in| is copied into the directory specified by
//@|directory_out|.  You can also use @|copyfile| to copy entire directories
//as in
//@[
//   copyfile(dir_in,dir_out)
//@]
//in which case the directory contents are copied to the destination directory
//(which is created if necessary).  Finally, the first argument to @|copyfile| can
//contain wildcards
//@[
//   copyfile(pattern,directory_out)
//@]
//in which case all files that match the given pattern are copied to the output
//directory.   Note that to remain compatible with the MATLAB API, this function
//will delete/replace destination files that already exist, unless they are marked
//as read-only.  If you want to force the copy to succeed, you can append a @|'f'|
//argument to the @|copyfile| function:
//@[
//   copyfile(arg1,arg2,'f')
//@]
//or equivalently
//@[
//   copyfile arg1 arg2 f
//@]
//@@Signature
//function copyfile CopyFileFunction
//inputs pattern directory_out forceflag
//outputs none
//!
static void CopyFile(QString source, QString dest, bool override) {
  QFileInfo destInfo(dest);
  if (destInfo.exists() && (override || destInfo.isWritable()))
    QFile::remove(dest);
  QFile::copy(source,dest);
}

static void CopyDirectoryRecursive(QString srcdir, QString destdir, bool override) {
  QDir dir(srcdir);
  dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
  QFileInfoList list = dir.entryInfoList();
  for (int i=0;i<list.size();i++) {
    QFileInfo fileInfo = list.at(i);
    if (fileInfo.isDir())
      CopyDirectoryRecursive(fileInfo.absoluteFilePath(),
			     destdir+QDir::separator()+fileInfo.fileName(),
			     override);
    else 
      if (QDir::current().mkpath(destdir))
	CopyFile(fileInfo.absoluteFilePath(),
		 destdir+QDir::separator()+fileInfo.fileName(),override);
  }
}

ArrayVector CopyFileFunction(int nargout, const ArrayVector& arg) {
  if (arg.size() < 2)
    throw Exception("copyfile requires two arguments - source and destination");
  bool override = ((arg.size() == 3) && (arg[2].asString().toUpper() == "F"));
  QString source(arg[0].asString());
  QString dest(arg[1].asString());
  QFileInfo source_info(source);
  QFileInfo dest_info(dest);
  // Case 1 - source is a file, and dest is a file
  if (source_info.isFile() && !dest_info.isDir()) {
    // Simple copy of files
    CopyFile(source,dest,override);
  } else if (source_info.isFile() && dest_info.isDir()) {
    CopyFile(source,dest + QDir::separator() + source_info.fileName(),override);
  } else if (source_info.isDir() && dest_info.isFile()) {
    throw Exception("cannot copy a directory to a file");
  } else if (source_info.isDir() && (dest_info.isDir() || !dest_info.exists())) {
    // Copy the contents of a directory 
    CopyDirectoryRecursive(source,dest,override);
  } else if ((source.count("*") > 0) && (dest_info.isDir() || !dest_info.exists())) {
    // Try and get to the directory
    QDir sourcedir(source_info.path());
    if (!sourcedir.exists()) 
      return ArrayVector();
    sourcedir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    sourcedir.setNameFilters(QStringList() << source_info.fileName());
    QFileInfoList list = sourcedir.entryInfoList();
    for (int i=0;i<list.size();i++) {
      QFileInfo fileInfo = list.at(i);
      if (fileInfo.isDir())
	CopyDirectoryRecursive(fileInfo.absoluteFilePath(),
			       dest+QDir::separator()+fileInfo.fileName(),
			       override);
      else 
	if (QDir::current().mkpath(dest))
	  CopyFile(fileInfo.absoluteFilePath(),dest+QDir::separator()+fileInfo.fileName(),override);
    }
  } else
    throw Exception("unhandled case of copyfile function");
  return ArrayVector();
}