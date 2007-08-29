%!
%@Module CSTRUCTREAD Read a C Structure From File
%@@Section EXTERNAL
%@@Usage
%The @|cstructread| function is a convenience function for
%reading a C structure from a file.  This is generally a
%very bad idea, as direct writing of C structures to files
%is notoriously unportable.  Consider yourself warned.  The
%syntax for this function is
%@[
%   a = cstructread(fid,'typename')
%@]
%where @|'typename'| is a string containing the name of the
%C structure as defined using @|cstructdefine|, and @|fid|
%is the file handle returned by the @|fopen| command.  Note
%that this form will read a single structure from the file.
%If you want to read multiple structures into an array, 
%use the following form
%@[
%   a = cstructread(fid,'typename',count)
%@]
%Note that the way this function works is by using @|cstructsize|
%to compute the size of the structure, reading that many bytes
%from the file, and then calling @|cstructthaw| on the resulting
%buffer.  A consequence of this behavior is that the byte-endian
%corrective behavior of FreeMat does not work.
%!
function a = cstructread(fid,typename,count)
  if (nargin < 3), count = 1; end;
  if (nargin < 2), error('cstructread requries at least a file id and a typename'); end;
  p = fread(fid,[1,cstructsize(typename,count)],'uint8');
  a = cstructthaw(p,typename,count);

