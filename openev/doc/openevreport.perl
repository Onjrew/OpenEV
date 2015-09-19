package main;

&do_require_package('report');
&do_require_package('graphicx');
&do_require_package('html');

sub do_env_members {
    &do_env_description;
}

&ignore_commands( <<_IGNORED_CMDS_);
headtext # {}
foottext # {}
_IGNORED_CMDS_

1;   # Must be last line
