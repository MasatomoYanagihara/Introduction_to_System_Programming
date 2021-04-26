#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
   pid_t pid;
   char line[256], readFileDescriptor[5], writeFileDescriptor[5], word[256];
   int wordCount, fileDescriptor[2], st, returnValue1, returnValue2;

   returnValue1 = pipe(fileDescriptor); // バッファへのパイプを開く
   if (returnValue1 < 0)
   {
      perror("pipe");
      exit(1);
   }

   // int型からchar型に変換（コマンドライン引数で渡す為）
   snprintf(readFileDescriptor, sizeof(readFileDescriptor), "%d", fileDescriptor[0]);
   snprintf(writeFileDescriptor, sizeof(writeFileDescriptor), "%d", fileDescriptor[1]);

   fgets(line, sizeof(line), stdin);        // キーボードから文字列を入力
   returnValue1 = sscanf(line, "%s", word); // 改行を取り除いて配列wordに格納
   if (returnValue1 > 0)
   {
      pid = fork(); // 子プロセスを生成
      if (pid == 0)
      {
         returnValue2 = execl("pip_c", "pip_c", readFileDescriptor, writeFileDescriptor, NULL);
         if (returnValue2 < 0)
         {
            exit(1);
         }
      }
      write(fileDescriptor[1], word, sizeof(word)); // wordをバッファに書き込み
      wait(&st);                                    // 子プロセスが終了するまで待機

      read(fileDescriptor[0], &wordCount, sizeof(wordCount));
      fprintf(stderr, "「%s」の文字数は「%d」です。\n", word, wordCount);

      close(fileDescriptor[0]);
      close(fileDescriptor[1]);
   }
   return 0;
}
/*
apple
apple <-> 5 
 */
