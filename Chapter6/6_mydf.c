#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/vfs.h>

int main(int argc, char *argv[])
{
   struct statfs buf;                          // statfs構造体（パーティションの情報用）の変数bufを宣言
   double gigaByte = 1024.0 * 1024.0 * 1024.0; // GBで表示する為に作成
   int useBlocks, returnValue;

   sync(); // メモリ上のスーパーブロックの情報をハードディスクに出力
   returnValue = statfs(argv[1], &buf);
   if (returnValue < 0) // 失敗したらexit
   {
      exit(0);
   }
   fprintf(stderr, "%.1f GB\n", buf.f_blocks * buf.f_bsize / gigaByte);          // ファイルシステムの全容量
   useBlocks = buf.f_blocks - buf.f_bfree;                                       // 使用しているブロック数を計算
   fprintf(stderr, "used size=%.0f GB\n", useBlocks * buf.f_bsize / gigaByte);   // 使用容量
   fprintf(stderr, "free size=%.0f GB\n", buf.f_bfree * buf.f_bsize / gigaByte); // 空き容量
   fprintf(stderr, "used rasio=%.0f %%\n", 100.0 * useBlocks / buf.f_blocks);    // 使用容量の割合
   return 0;
}
