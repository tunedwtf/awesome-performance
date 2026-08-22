#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *a;
    int length;
    int capacity;
};

void initialize(struct Array *ar, int len, int cap) {
    ar->a = (int *)malloc(cap * sizeof(int));
    ar->length = len;
    ar->capacity = cap;
}

void print(struct Array *ar) {
    printf("elements of the array: \n");
    for (int i=0;i<ar->length;i++) {
        printf("%d\n", ar->a[i]);
    }
}

void append(struct Array *ar, int elem) {
    if (ar->length < ar->capacity)
        ar->a[ar->length] = elem;    
    ar->length++;
}

void insert(struct Array *ar, int index, int elem) {
    // check if index > 0 & index < ar.length - 1
    if (index >= 0 && index < ar->length) {
        for (int i=ar->length;i>index;i--) {
            ar->a[i] = ar->a[i-1];
        }
        ar->a[index] = elem;
        ar->length++;
    }
}

void delete(struct Array *ar, int index) {
    // check if index > 0 & index < ar.length - 1
    if (index >= 0 && index < ar->length) {
        for (int i=index;i<ar->length-1;i++) {
            ar->a[i] = ar->a[i+1];
        }
        ar->length--;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(struct Array *ar, int elem) {
    for (int i=0;i<ar->length;i++) {
        if (ar->a[i] == elem) {
            // INFO: linear search optimization techniques - 
            // INFO: transposition
            // swap(&ar->a[i], &ar->a[i-1]);
            // INFO: move to head
            swap(&ar->a[i], &ar->a[0]);
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array *ar, int elem) {
    int l=0, h=ar->length;
    while (l < h) {
        int mid=(l+h)/2;
        if (ar->a[mid] == elem) {
            return mid;
        } else if (ar->a[mid] < elem) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1;
}

int get(struct Array *ar, int index) {
    if (index >= 0 && index < ar->length) {
        return ar->a[index];
    }
    return -1;
}

void set(struct Array *ar, int index, int elem) {
    if (index >= 0 && index < ar->length) {
        ar->a[index] = elem;
    }
}

int min(struct Array *ar) {
    int min = ar->a[0];
    for(int i=0;i<ar->length;i++) {
        if (ar->a[i] < min) min = ar->a[i];
    }
    return min;
}

int max(struct Array *ar) {
    int max = ar->a[0];
    for(int i=0;i<ar->length;i++) {
        if (ar->a[i] > max) max = ar->a[i];
    }
    return max;
}

int sum(struct Array *ar) {
    int sum = 0;
    for(int i=0;i<ar->length;i++) {
        sum += ar->a[i];
    }
    return sum;
}

void reverse(struct Array *ar) {
    int i=0,j=ar->length-1;
    while (i<j) {
        int temp = ar->a[i];
        ar->a[i] = ar->a[j];
        ar->a[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    struct Array ar;
    initialize(&ar, 0, 10);

    append(&ar, 10);
    append(&ar, 20);
    append(&ar, 30);
    append(&ar, 40);
    append(&ar, 50);

    insert(&ar, 2, 45);

    printf("before deletion\n");
    print(&ar);
    
    delete(&ar, 2);
    
    
    printf("after deletion\n");

    // printf("10 is at index: %d\n", linearSearch(&ar, 10));
    // printf("50 is at index: %d\n", linearSearch(&ar, 50));
    printf("50 is at index: %d\n", binarySearch(&ar, 50));
    print(&ar);

    printf("reverse");
    reverse(&ar);

    print(&ar);

    return 0;
}