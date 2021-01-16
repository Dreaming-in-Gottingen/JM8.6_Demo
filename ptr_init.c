#include <stdio.h>
#include <stdlib.h>

void mem_alloc(char **pp)
{
    *pp = (char*)malloc(64);
}

int main()
{
    char *ptr0;
    char *ptr1;
    char *ptr2;

    char ch = 'A';
    ptr0 = &ch;                 //ptr0指向stack变量ch
    ptr1 = (char*)&ptr2;        //ptr1指向ptr2这个stack变量的地址
    mem_alloc(&ptr2);           //给ptr2这个stack变量赋值，赋值为heap空间地址
    printf("stack_addr: &ptr0=%p, &ptr1=%p, &ptr2=%p, &ch=%p\n", &ptr0, &ptr1, &ptr2, &ch);
    printf("ptr_val: ptr0=%p, ptr1=%p, ptr2=%p\n", ptr0, ptr1, ptr2);
}
