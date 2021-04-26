#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
   mode_t mode;
   struct stat buf;
   int returnValue;

   returnValue = stat(argv[1], &buf);
   if (returnValue < 0)
   {
      perror("stat");
      return 1;
   }

   mode = buf.st_mode & ~0066;

   returnValue = chmod(argv[1], mode);
   if (returnValue < 0)
   {
      perror("chmod");
      return 1;
   }
   return 0;
}
