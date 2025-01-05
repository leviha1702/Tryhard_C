#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Nhap mang
void nhapMang(int arr[], int n) {
    printf("Nhap %d so nguyen: \n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Xuat mang
void xuatMang(int arr[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Dem so luong so nguyen am o vi tri le (su dung de quy)
int demSoAmViTriLe(int arr[], int n, int index) {
    if (index >= n) return 0;
    int count = (index % 2 == 1 && arr[index] < 0) ? 1 : 0;
    return count + demSoAmViTriLe(arr, n, index + 1);
}

// Dem so phan tu la boi cua x (su dung de quy)
int demBoiCuaX(int arr[], int n, int x, int index) {
    if (index >= n) return 0;
    int count = (arr[index] % x == 0) ? 1 : 0;
    return count + demBoiCuaX(arr, n, x, index + 1);
}

// Kiem tra so chinh phuong
bool laSoChinhPhuong(int num) {
    if (num < 0) return false;
    int sqrtNum = (int)sqrt(num);
    return sqrtNum * sqrtNum == num;
}

// Tinh tong cac so chinh phuong (su dung de quy)
int tongSoChinhPhuong(int arr[], int n, int index) {
    if (index >= n) return 0;
    int sum = laSoChinhPhuong(arr[index]) ? arr[index] : 0;
    return sum + tongSoChinhPhuong(arr, n, index + 1);
}

// Kiem tra toan bo so trong mang co phai so le hay khong (su dung de quy)
bool tatCaSoLe(int arr[], int n, int index) {
    if (index >= n) return true;
    if (arr[index] % 2 == 0) return false;
    return tatCaSoLe(arr, n, index + 1);
}

// Kiem tra mang co theo thu tu giam dan hay khong (su dung de quy)
bool laMangGiamDan(int arr[], int n, int index) {
    if (index >= n - 1) return true;
    if (arr[index] < arr[index + 1]) return false;
    return laMangGiamDan(arr, n, index + 1);
}

// Ham main
int main() {
    int n;
    do {
        printf("Nhap so luong phan tu cua mang (3 <= n < 100): ");
        scanf("%d", &n);
    } while (n <= 2 || n >= 100);

    int arr[n];
    nhapMang(arr, n);
    xuatMang(arr, n);

    // Dem so nguyen am o vi tri le
    int soAmViTriLe = demSoAmViTriLe(arr, n, 0);
    printf("So luong so nguyen am o vi tri le: %d\n", soAmViTriLe);

    // Dem so phan tu la boi cua x
    int x;
    printf("Nhap gia tri x de kiem tra boi: ");
    scanf("%d", &x);
    int soPhanTuBoiX = demBoiCuaX(arr, n, x, 0);
    printf("So phan tu la boi cua %d: %d\n", x, soPhanTuBoiX);

    // Tinh tong cac so chinh phuong
    int tongChinhPhuong = tongSoChinhPhuong(arr, n, 0);
    printf("Tong cac so chinh phuong: %d\n", tongChinhPhuong);

    // Kiem tra toan bo so co phai so le hay khong
    if (tatCaSoLe(arr, n, 0)) {
        printf("Tat ca cac phan tu trong mang deu la so le.\n");
    } else {
        printf("Khong phai tat ca cac phan tu trong mang deu la so le.\n");
    }

    // Kiem tra mang co theo thu tu giam dan hay khong
    if (laMangGiamDan(arr, n, 0)) {
        printf("Mang theo thu tu giam dan.\n");
    } else {
        printf("Mang khong theo thu tu giam dan.\n");
    }

    return 0;
}
