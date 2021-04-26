#include <stdio.h>
struct linear
{
   int data;
   struct linear *nextAddress; //struct linearのアドレスが入るポインタ変数nextAddress
};

int main()
{
   int i;
   struct linear arr[5], *pointer, *currentAddress;
   pointer = arr; // arr[0]のアドレスをポインタ変数pointerに代入
   for (i = 0; i < 5; i++)
   {
      scanf("%d", &pointer->data);
      currentAddress = pointer;
      currentAddress->nextAddress = ++pointer;
   }
   currentAddress->nextAddress = NULL;

   pointer = arr; // arr[0]のアドレスをポインタ変数pointerに代入
   while (pointer != NULL)
   {
      fprintf(stderr, "%d\n", pointer->data);
      pointer = pointer->nextAddress;
   }

   return 0;
}
