#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selsort(int a[], int n) {
    int t, pos;
    for(int i = 0; i < n - 1; i++) {
        pos = i;
        for(int j = i + 1; j < n; j++) {
            if (a[j] < a[pos]) {
                pos = j;
            }
        }
        t = a[i];
        a[i] = a[pos];
        a[pos] = t;
    }
}

int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while(1) {
        printf(" 1:For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Enter array elements: ");
                for(i = 0; i < n; i++) {
                    scanf("%d", &a[i]);
                }
                start = clock();
                selsort(a, n);
                end = clock();
                printf("Sorted array is: ");
                for(i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("Time taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                break;

            case 2:
                n = 500;
                while(n <= 14500) {
                    for(i = 0; i < n; i++) {
                        a[i] = n - i;
                    }
                    start = clock();
                    selsort(a, n);
                    // Dummy loop to create delay
                    for(j = 0; j < 500000; j++) {
                        temp = 38 / 600;
                    }
                    end = clock();
                    printf("Time taken to sort %d numbers is %f Secs\n", n, ((double)(end - start)) / CLOCKS_PER_SEC);
                    n += 1000;
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

