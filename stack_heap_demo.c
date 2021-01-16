#include <stdio.h>
#include <stdlib.h>

void stack_test()
{
    int tmp0;
    int tmp1;
    int tmp2;
    printf("stack_addr: &tmp0=%p, &tmp1=%p, &tmp2=%p\n", &tmp0, &tmp1, &tmp2);
}

void heap_test()
{
    char *ptr0 = (char*)malloc(64);
    char *ptr1 = (char*)malloc(64);
    char *ptr2 = (char*)malloc(64);
    printf("heap_addr: ptr0=%p, ptr1=%p, ptr2=%p\n", ptr0, ptr1, ptr2);
}

int main(void)
{
    stack_test();
    heap_test();
}
