#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int get_path(char *dir[]);

int main()
{
   pid_t pid;
   int returnValue, st, i = 0;
   char line[256], command[256], path[512], *dir[64];
   get_path(dir);

   while (1)
   {
      fprintf(stderr, "--> ");          // プロンプトを表示
      fgets(line, sizeof(line), stdin); // 入力を受け付け
      sscanf(line, "%s", command);      // 改行を除く
      pid = fork();                     // 子プロセスを生成
      if (pid == 0)
      {
         returnValue = execl(command, command, NULL); // コマンドを実行
         if (returnValue < 0)                         // 実行できなかった場合（返り値が-）
         {
            for (i = 0; dir[i] != NULL; i++)
            {
               sprintf(path, "%s/%s", dir[i], command); // dir[i]に"/"とcommandを連結しpathに代入
               execl(path, path, NULL);                 // pathを実行
            }
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
int get_path(char *dir[])
{
   char *env;
   int i = 0;
   env = getenv("PATH"); // 環境変数PATHの値を取得しenvに代入
   dir[i] = strtok(env, ":");
   while (dir[i] != NULL)
   {
      i++;
      dir[i] = strtok(NULL, ":");
   }
   return i;
}
