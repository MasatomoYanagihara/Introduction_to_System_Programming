#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(void)
{
    pid_t pid;
    int status, returnValue;
    char line[256], command[256];
    while (1)
    {
        fprintf(stderr, "--> ");
        fgets(line, sizeof(line), stdin); // ストリームから入力
        sscanf(line, "%s", command);      // 改行を除く
        pid = fork();
        if (pid == 0)
        {
            returnValue = execl(command, command, NULL);
            if (returnValue < 0)
            {
                exit(0);
            }
        }
        else
        {
            wait(&status); // 子プロセスの終了を待つ
        }
    }
    return 0;
}
