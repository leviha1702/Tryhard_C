#include <stdio.h>

// Hàm tìm phần tử lớn nhất bằng kỹ thuật chia để trị
int findMax(int arr[], int left, int right) {
    if (left == right) {
        return arr[left]; // Trường hợp cơ sở
    }

    int mid = (left + right) / 2;
    int maxLeft = findMax(arr, left, mid);
    int maxRight = findMax(arr, mid + 1, right);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}
// Hàm đếm số lần xuất hiện của x trong mảng
int countOccurrences(int arr[], int left, int right, int x) {
    if (left == right) {
        return (arr[left] == x) ? 1 : 0; // Trường hợp cơ sở
    }

    int mid = (left + right) / 2;
    int countLeft = countOccurrences(arr, left, mid, x);
    int countRight = countOccurrences(arr, mid + 1, right, x);

    return countLeft + countRight;
}
// Hàm tìm phần tử xuất hiện nhiều nhất trong mảng
int mostFrequent(int arr[], int n) {
    int maxCount = 0;
    int mostFreq = arr[0];

    for (int i = 0; i < n; i++) {
        int count = countOccurrences(arr, 0, n - 1, arr[i]);
        if (count > maxCount) {
            maxCount = count;
            mostFreq = arr[i];
        }
    }

    return mostFreq;
}
int main() {
    int array[] = {3, 1, 9, 4, 7, 6};
    int n = sizeof(array) / sizeof(array[0]);

    int max = findMax(array, 0, n - 1);
    printf("phan tu lon nhat: %d\n", max);

    int x = 9;
    int count = countOccurrences(array, 0, n - 1, x);
    printf("so lan xuat hien cua phan tu %d: %d\n", x, count);

    int result = mostFrequent(array, n);
    printf("phan tu xuat hien nhieu nhat: %d\n", result);
    return 0;
}