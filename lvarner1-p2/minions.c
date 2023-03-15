#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

void* minion_print(void* u)
{
    int min = *((int*) u);
    printf("Hello! I am minion %d\n", min);
    return NULL;
}

void* overlord_print(void* unused)
{
    printf("Hello Minions! I am the Overlord!\n");
    return NULL;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: Bad command line parameters\n");
        exit(1);
    }

    int min = 0;
    min = atoi(argv[1]);
    if (min < 0)
    {
        fprintf(stderr, "Error: Bad command line parameters\n");
        exit(1);
    }

    int minion_nums[min];
    pthread_t minions[min];
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < min; i++)
    {
        minion_nums[i] = i;
        if (pthread_create(&minions[i], &attr, minion_print, &minion_nums[i]) != 0)
        {
            fprintf(stderr, "Failed to create pthread, error code %d\n", errno);
            exit(errno);
        }
    }

    pthread_attr_destroy(&attr);

    for (int i = 0; i < min; i++)
    {
        pthread_join(minions[i], NULL);
    }

    pthread_t overlord;
    pthread_attr_init(&attr);

    if (pthread_create(&overlord, &attr, overlord_print, NULL) != 0)
    {
        fprintf(stderr, "Failed to create pthread, error code %d\n", errno);
        exit(errno);
    }

    pthread_attr_destroy(&attr);
    pthread_join(overlord, NULL);

    return 0;
}
