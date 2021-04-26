#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir; // ディレクトリ構造体のアドレスが入るポインタ変数dirを宣言
    struct dirent *directoryEntry; // ディレクトリエントリのデータが入るdirent構造体の変数directoryEntryを宣言

    dir = opendir(argv[1]); // 指定したパスのディレクトリをオープン

    while ((directoryEntry = readdir(dir)) != NULL)
    {
        // inode番号とファイル名を表示
        printf("%lu %s\n", directoryEntry->d_ino, directoryEntry->d_name);
    }
    closedir(dir); // ディレクトリをクローズ
    return 0;
}