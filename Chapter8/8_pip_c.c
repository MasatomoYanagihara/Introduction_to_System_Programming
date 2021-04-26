#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argCount, char *argValue[])
{
   char word[256];
   int wordCount, readFileDescriptor, writeFileDescriptor;

   // char型からint型に変換（read()、write()で使用する為）
   readFileDescriptor = atoi(argValue[1]);
   writeFileDescriptor = atoi(argValue[2]);

   read(readFileDescriptor, word, sizeof(word));

   wordCount = strlen(word); // 読み取った文字列の長さをカウント
   sleep(10);

   write(writeFileDescriptor, &wordCount, sizeof(wordCount)); // バッファに書き込み

   close(readFileDescriptor);
   close(writeFileDescriptor);
   return 0;
}
