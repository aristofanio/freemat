function begingroup(&p,groupname)
  p.groupname = groupname;
  if (strcmp(lower(groupname),'tests'))
    p.ignore = 1;
  else
    fprintf(p.myfile,'<H3>%s</H3>\n',groupname);
    p.ignore = 0;
  end
