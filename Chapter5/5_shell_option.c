#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int get_arg(char *c, char *arg[]);

int main()
{
   pid_t pid;
   int ret, st, i = 0;
   char line[256], command[256], *arg[32];
   while (1)
   {
      fprintf(stderr, "--> ");          // プロンプトを表示
      fgets(line, sizeof(line), stdin); // 入力受付け
      sscanf(line, "%[^\n]", command);  // 入力されたオプション付きのコマンドを配列commandに代入
      get_arg(command, arg);            // 配列command内を" "で区切り、各区切りの先頭アドレスを配列argに代入

      pid = fork();
      if (pid == 0)
      {
         ret = execv(arg[0], arg);
         if (ret < 0)
         {
            exit(0);
         }
      }
      else
      {
         wait(&st);
      }
   }
   return 0;
}
int get_arg(char *c, char *arg[])
{
   int i = 0;
   arg[i] = strtok(c, " ");
   while (arg[i] != NULL)
   {
      i++;
      arg[i] = strtok(NULL, " ");
   }
   return i;
}
