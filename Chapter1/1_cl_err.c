#include <stdio.h>

int main(int argCount, char *argValue[])
{
    // コマンドライン引数が３つ以外の場合はエラーとする
    if (argCount != 3)
    {
        fprintf(stderr, "Usage:cl_err f1 f2\n");
        return 1;
    }
    fprintf(stderr, "OK\n");
    return 0;
}