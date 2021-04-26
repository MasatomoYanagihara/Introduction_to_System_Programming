#include <stdio.h>

int main(int argCount, char *argValue[])
{
    fprintf(stderr, "argCount=%d\n", argCount);       // 引数の数
    fprintf(stderr, "argValue[0]=%s\n", argValue[0]); // 実行ファイルの先頭アドレス
    fprintf(stderr, "argValue[1]=%s\n", argValue[1]);
    fprintf(stderr, "argValue[2]=%s\n", argValue[2]);
    return 0;
}
