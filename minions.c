#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* foo(void* unused)
{
    printf("Hello world from thread\n");
    return NULL;
}

int main(void)
{
    printf("Hello world\n");
    pthread_t thread;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&thread, &attr, foo, NULL);
    pthread_join(thread, NULL);
    pthread_attr_destroy(&attr);

    return 0;
}