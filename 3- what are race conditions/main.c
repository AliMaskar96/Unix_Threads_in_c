#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;

void* routine()
{
    int i;

    i = 0;
    while (i < 1000000)
    {
        mails++;
        i++;
    }
}

int main(int argc, char* argv[])
{
    pthread_t p1, p2, p3, p4;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 4;
    }
    printf("Number of mails: %d\n", mails);
    return 0;
}

// Number of mails: 1220594 
// We need : 2000000 
// Les deux threads n'ont pas pu incrementer mails comme il faut ----> Data Race !!