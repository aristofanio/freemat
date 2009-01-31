
% Copyright (c) 2002-2007 Samit Basu
% Licensed under the GPL

function outputtext(&p,text)
  if (p.ignore) return; end
  text(end) = [];
  v = regexp(text,'@\$([^\|].*)\|(.*)','tokens');
  if (isempty(v))
    printf(sprintf('bad line: %s',text));
    return;
  end
  % Search for inputs
  ttype = v{1}{1};
  if (~any(strcmp(ttype,{'near','exact','near_permute'})))
    printf(sprintf('bad test type in line: %s',text));
    return;
  end
  expr = v{1}{2};
  vars = symvar(expr);
  pnt = regexp(vars,'x.');
  in_count = 0; 
  for i=1:numel(pnt); 
    if (~isempty(pnt{i}))
      in_count = in_count + 1; 
    end; 
  end
  pnt = regexp(vars,'y.');
  out_count = 0;
  for i=1:numel(pnt);
    if (~isempty(pnt{i}))
      out_count = out_count + 1;
    end;
  end
  funcname = sprintf('wbtest_%s_%d',p.modulename,p.num);
  mkdir(sprintf('%s/toolbox/test',p.sourcepath));
  mkdir(sprintf('%s/toolbox/test/reference',p.sourcepath));

  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  % Write the test file
  filename = sprintf('%s/toolbox/test/%s.m',p.sourcepath,funcname);
  fp = fopen(filename,'w');
  if (fp < 0)
    error(sprintf('unable to open %s for output',filename));
  end
  fprintf(fp,'function test_val = %s(verbose)\n',funcname);
  fprintf(fp,'  load reference/wbinputs.mat\n');
  fprintf(fp,'  load reference/%s_ref.mat\n',funcname);
  fprintf(fp,'  fail_count = 0;\n');
  if (in_count == 0)
    fprintf(fp,'  error_flag = 0;\n');
    for k=1:out_count
      fprintf(fp,'  y%d = [];\n',k);
    end
    fprintf(fp,'  try\n');
    fprintf(fp,'    %s;\n',expr);
    fprintf(fp,'  catch\n');
    fprintf(fp,'    error_flag = 1;\n');
    fprintf(fp,'  end\n'); 
    fprintf(fp,'  if (error_flag && ~error_refs)\n');
    fprintf(fp,'     printf(''Mismatch Errors: %s\\n'');\n',expr);
    fprintf(fp,'     fail_count = fail_count + 1;\n');
    for k=1:out_count
      fprintf(fp,'  elseif (~error_flag && ~error_refs && ~wbtest_%s(y%d,y%d_refs{1}))\n',ttype,k,k);
      fprintf(fp,'    printf(''Mismatch (%s): output %d %s\\n'');\n',ttype,k,expr);
      fprintf(fp,'    fail_count = fail_count + 1;\n');
      fprintf(fp,'  end\n');
    end
  elseif (in_count == 1)
    fprintf(fp,'  for loopi=1:numel(wbinputs)\n');
    fprintf(fp,'    x1 = wbinputs{loopi};\n');
    fprintf(fp,'    error_flag = 0;\n');
    for k=1:out_count
      fprintf(fp,'  y%d = [];\n',k);
    end
    fprintf(fp,'    try\n');
    fprintf(fp,'      %s;\n',expr);
    fprintf(fp,'    catch\n');
    fprintf(fp,'      error_flag = 1;\n');
    fprintf(fp,'    end\n');
    fprintf(fp,'    if (error_flag && ~error_refs(loopi))\n');
    fprintf(fp,'       printf(''Mismatch Errors: input %%d %s\\n'',loopi);\n',expr);
    fprintf(fp,'        fail_count = fail_count + 1;\n');
    for k=1:out_count
      fprintf(fp,'  elseif (~error_flag && ~error_refs && ~wbtest_%s(y%d,y%d_refs{loopi}))\n',ttype,k,k);
      fprintf(fp,'    printf(''Mismatch (%s): input %%d output %d %s\\n'',loopi);\n',ttype,k,expr);
      fprintf(fp,'    fail_count = fail_count + 1;\n');
      fprintf(fp,'  end\n');
    end
  elseif (in_count == 2)
    fprintf(fp,'  for loopi=1:numel(wbinputs)\n');
    fprintf(fp,'    for loopj=1:numel(wbinputs)\n');
    fprintf(fp,'      x1 = wbinputs{loopi};\n');
    fprintf(fp,'      x2 = wbinputs{loopj};\n');
    fprintf(fp,'      error_flag = 0;\n');
    for k=1:out_count
      fprintf(fp,'     y%d = [];\n',k);
    end
    fprintf(fp,'      try\n');
    fprintf(fp,'        %s;\n',expr);
    fprintf(fp,'      catch\n');
    fprintf(fp,'        error_flag = 1;\n');
    fprintf(fp,'      end\n');
    fprintf(fp,'    if (error_flag && ~error_refs(loopi,loopj))\n');
    fprintf(fp,'       printf(''Mismatch Errors: input %%d, %%d %s\\n'',loopi,loopj);\n',expr);
    fprintf(fp,'        fail_count = fail_count + 1;\n');
    for k=1:out_count
      fprintf(fp,'  elseif (~error_flag && ~error_refs && ~wbtest_%s(y%d,y%d_refs{loopi,loopj}))\n',ttype,k,k);
      fprintf(fp,'    printf(''Mismatch (%s): input %%d,%%d output %d %s\\n'',loopi,loopj);\n',ttype,k,expr);
      fprintf(fp,'    fail_count = fail_count + 1;\n');
      fprintf(fp,'  end\n');
    end
    fprintf(fp,'    end\n');
    fprintf(fp,'  end\n');
  end
  fprintf(fp,'  test_val = (fail_count == 0);\n');
  fprintf(fp,'end\n');
  fclose(fp);

  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  
  % Write the reference file
  filename = sprintf('%s/toolbox/test/reference/gen_%s.m',p.sourcepath,funcname);
  fp = fopen(filename,'w');
  if (fp < 0)
    error(sprintf('unable to open %s for output',filename));
  end
  fprintf(fp,'function gen_%s(verbose)\n',funcname);
  fprintf(fp,'  load wbinputs.mat\n');
  if (in_count == 0)
    fprintf(fp,'  error_refs = 0;\n');
    for k=1:out_count
      fprintf(fp,'  y%d = [];\n',k);
    end
    fprintf(fp,'  try\n');
    fprintf(fp,'    %s;\n',expr);
    fprintf(fp,'  catch\n');
    fprintf(fp,'    error_refs = 1;\n');
    fprintf(fp,'  end\n'); 
    fprintf(fp,'  if (~error_refs)\n');
    for k=1:out_count
      fprintf(fp,'  y%d_refs = {y%d};\n',k,k);
    end
    fprintf(fp,'  end\n');
  elseif (in_count == 1)
    fprintf(fp,'  n_ = numel(wbinputs);\n');
    fprintf(fp,'  error_refs = zeros(n_,1);\n');
    for k=1:out_count
      fprintf(fp,'  y%d_refs = cell(n_,1);\n',k);
    end
    fprintf(fp,'  for loopi=1:n_\n');
    fprintf(fp,'    x1 = wbinputs{loopi};\n');
    fprintf(fp,'    error_refs(loopi) = 0;\n');
    for k=1:out_count
      fprintf(fp,'    y%d = [];\n',k);
    end
    fprintf(fp,'    try\n');
    fprintf(fp,'      %s;\n',expr);
    fprintf(fp,'    catch\n');
    fprintf(fp,'      error_refs(loopi) = 1;\n');
    fprintf(fp,'    end\n');
    fprintf(fp,'    if (~error_refs(loopi))\n');
    for k=1:out_count
      fprintf(fp,'     y%d_refs(loopi) = {y%d};\n',k,k);
    end;
    fprintf(fp,'    end\n');
    fprintf(fp,'  end\n');
  elseif (in_count == 2)
    fprintf(fp,'  n_ = numel(wbinputs);\n');
    fprintf(fp,'  error_refs = zeros(n_,n_);\n');
    for k=1:out_count
      fprintf(fp,'  y%d_refs = cell(n_,n_);\n',k);
    end
    fprintf(fp,'  for loopi=1:n_\n');
    fprintf(fp,'    for loopj=1:n_\n');
    fprintf(fp,'      x1 = wbinputs{loopi};\n');
    fprintf(fp,'      x2 = wbinputs{loopj};\n');
    for k=1:out_count
      fprintf(fp,'      y%d = [];\n',k);
    end
    fprintf(fp,'      try\n');
    fprintf(fp,'        %s;\n',expr);
    fprintf(fp,'      catch\n');
    fprintf(fp,'        error_refs(loopi,loopj) = 1;\n');
    fprintf(fp,'      end\n');
    fprintf(fp,'      if (~error_refs(loopi,loopj))\n');
    for k=1:out_count
      fprintf(fp,'       y%d_refs(loopi,loopj) = {y%d};\n',k,k);
    end
    fprintf(fp,'      end\n');
    fprintf(fp,'    end\n');
    fprintf(fp,'  end\n');
  end
  fprintf(fp,'  save %s_ref.mat error_refs',funcname);
  for k=1:out_count
    fprintf(fp,'  y%d_refs ',k);
  end
  fprintf(fp,'\nend\n');
  fclose(fp);
  
  
  
%  filename = sprintf('%s/toolbox/test/matlab/wbgen_%s_d.m',p.sourcepath,p.module,p.num);
%  fp = fopen(filename,'w');
%  if (fp < 0)
%    error(sprintf('unable to open %s for output',filename));
%  end
%  fprintf(fp,'function ');
  
  p.num = p.num + 1;