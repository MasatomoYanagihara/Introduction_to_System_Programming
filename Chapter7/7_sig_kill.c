#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
   int returnValue;
   pid_t pid;
   if (argc != 2)
   {
      fprintf(stderr, "Only one PID is required\n");
      exit(1);
   }
   pid = atoi(argv[1]); // 整数値に変換

   returnValue = kill(pid, SIGKILL); // SIGKILLをシグナル送信
   if (returnValue < 0)
   {
      perror("kill");
   }
   return 0;
}
