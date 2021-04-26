#include <stdio.h>
#include <stdlib.h>
#include <signal.h> //usr/include/asm/signal.h
#include <time.h>
#include <unistd.h>

time_t startTime;
void stop(int signalNumber);

int main()
{
   time(&startTime);     // startTimeにLinux時間が入る
   signal(SIGINT, stop); // SIGINTを受信したらstop関数を実行する
   while (1)
   {
      // 1秒ごとに「.」を表示
      sleep(1);
      fprintf(stderr, ".");
   }
   return 0;
}

void stop(int signalNumber)
{
   time_t endTime;
   time(&endTime); // endTimeにLinux時間が入る
   fprintf(stderr, "\n signal number=%d, time= %ld\n", signalNumber, endTime - startTime);
   exit(0);
}
