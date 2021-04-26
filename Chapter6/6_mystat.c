#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  time_t time;
  int returnValue;
  returnValue = stat(argv[1], &buf); // ファイル情報をbufに出力
  if (returnValue < 0)
  {
    perror("stat");
    exit(1);
  }
  printf("Size: %d byte\n", buf.st_size);           // ファイルサイズ
  printf("Access(Linux-Time): %d\n", buf.st_atime); //最終アクセス日時（Linux時間）
  printf("Access: %s", ctime(&buf.st_atime));       // 最終アクセス日時（読み易いようにctime関数を使用）
  printf("inode: %ld\n", buf.st_ino);               // inode番号
  return 0;
}
