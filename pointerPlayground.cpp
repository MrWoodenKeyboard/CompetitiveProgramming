#include <stdio.h>

int main(){
    int arr[3][2][2] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    printf("%d\n", arr);
    printf("%d\n", arr + 1);
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[0][0]);
    printf("%d\n", arr[0][3]);
    printf("%d\n", arr[0][0][0]);
    printf("%d\n", arr[0][0][1]);
}
