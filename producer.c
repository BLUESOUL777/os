#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5; // buffer size

// wait operation
void wait(int *s) {
    (*s)--;
}

// signal operation
void signal(int *s) {
    (*s)++;
}

// producer
void producer() {
    if(mutex == 1 && empty != 0) {

        wait(&mutex);   // lock
        wait(&empty);   // reduce empty slots
        signal(&full);  // increase full slots

        printf("Produced item\n");

        signal(&mutex); // unlock
    } else {
        printf("Buffer FULL\n");
    }
}

// consumer
void consumer() {
    if(mutex == 1 && full != 0) {

        wait(&mutex);   // lock
        wait(&full);    // reduce full
        signal(&empty); // increase empty

        printf("Consumed item\n");

        signal(&mutex); // unlock
    } else {
        printf("Buffer EMPTY\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
        }

    } while(choice != 3);

    return 0;
}