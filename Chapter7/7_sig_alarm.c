#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void func(int x);

int main()
{
   int num1, num2, answer, inputAnswer;
   signal(SIGALRM, func); // シグナルハンドラの設定

   srand(time(NULL)); // 乱数の種を生成
   num1 = rand() % 100; // ランダムな整数を生成
   num2 = rand() % 100; // ランダムな整数を生成
   answer = num1 + num2;
   fprintf(stderr, "%d + %d ? ", num1, num2);

   alarm(5); // SIGALRMの発生時間（5秒）を指定
   scanf("%d", &inputAnswer);
   alarm(0); // 以前のalarmシステムコールの設定をキャンセル

   if (answer == inputAnswer)
   {
      fprintf(stderr, "You got it.\n");
   }
   else
   {
      fprintf(stderr, "That's wrong.\n");
   }
   return 0;
}
void func(int x)
{
   fprintf(stderr, "Time is up!\n");
}
