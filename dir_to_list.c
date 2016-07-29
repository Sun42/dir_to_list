#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include <sys/types.h>
#ifdef HAVE_NOT_DIRENT_H
#include <sys/dir.h>
#else
#include <dirent.h>
#endif


//int     stat(char *path, struct stat *sb);
//int     lstat(char *path, struct stat *sb);
//int     fstat(int fd, struct stat *sb);
//#include "dir_to_list.h"

void	dir_to_list(char *dossier);
void    parse_rep(DIR *rep);

int	main(int ac, char **av, char **environ)
{
  my_putstr(environ[0]);
  dir_to_list(av[1]);
  return (0);
}

void	dir_to_list(char *dossier)
{
  DIR	*rep;

  if (rep = opendir(dossier) == NULL)
    {
      my_putstr("Probleme d'ouverture du repertoire");
      exit(1);
    }
  parse_rep(rep);
  closedir(rep);
}

void	parse_rep(DIR *rep)
{
  struct stat   s_my_stats;
  t_list	*my_list;
  DIR		*fake_rep;
  char		*buffer;
  
#ifdef HAVE_NOT_DIRENT_H
  struct direct		*s_rep;
#else
  struct dirent		*s_rep;
#endif
 
  my_list = 0;
  while (s_rep = readdir(rep))
    {
      
      //my_putstr(getwd(buffer));
      //my_strcpy(absolute_path, getcwd);
      
      //my_strcat(absolute_path, s_rep->d_name);
      
      /*if (stat("test.txt", &s_my_stats) == -1)
	{
	  my_putstr(strerror(errno));
	  }*/
      my_putstr(s_rep->d_name);
      my_putstr("\n");
      
            //puis & bit a bit et comparaison avec S_IFDIR
    }
      my_show_str_in_list(my_list);
}

