#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <glib.h>

int
main (int argc, char **argv)
{
  struct stat st;
  int i;

  for (i = 1; i < argc; i++)
    {
      if (stat (argv[i], &st) == -1)
	perror ("stat"), exit (1);

      printf ("%s: st.st_mode = %o\n", argv[i], st.st_mode);
    }
  exit (0);
}
