%!
%@Module ISDIGIT Test for Digit Characters in a String
%@@Section STRING
%@@Usage
%The @|isdigit| functions returns a logical array that is 1 
%for characters in the argument string that are digits, and 
%is a logical 0 for characters in the argument that are not
%digits.  The syntax for its use is
%@[
%   x = isdigit(s)
%@]
%where @|s| is a @|string|.  
%@@Example
%A simple example of @|isdigit|:
%@<
%isdigit('numb3r5')
%@>
%!

function x = isdigit(s)
  s = int32(string(s));
  x = ((s >=48 ) & (s <= 57));
  
