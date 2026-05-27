#include <iostream>
#include <algorithm>
using namespace std;
void inMang(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]\n";
}
void vunDong(int arr[], int n, int i) {
    int Cha = i;
    int conTrai = 2 * i + 1;
    int conPhai = 2 * i + 2;

    if (conTrai < n && arr[conTrai] > arr[Cha]) {
        Cha = conTrai;
    }

    if (conPhai < n && arr[conPhai] > arr[Cha]) {
        Cha = conPhai;
    }

    if (Cha != i) {
        swap(arr[i], arr[Cha]);
        vunDong(arr, n, Cha);
    }
}
void taoDongBanDau(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        vunDong(arr, n, i);

        cout << "Vun dong tai nut i = " << i + 1 << ": ";
        inMang(arr, n);
    }
}
void sapXepHeap(int arr[], int n) {
    int buoc = 1;
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        vunDong(arr, i, 0);

        cout << "Buoc " << buoc << ": ";
        inMang(arr, n);

        buoc++;
    }
}

int main() {

    int arr1[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "--- XET MANG 1 ---" << endl;

    cout << "Mang ban dau: ";
    inMang(arr1, n1);

    cout << "\n--> TAO DONG BAN DAU:\n";
    taoDongBanDau(arr1, n1);

    cout << "\n--> SAP XEP HEAP SORT:\n";
    sapXepHeap(arr1, n1);

    cout << "\nMang sau khi sap xep: ";
    inMang(arr1, n1);

    cout << "\n====================================\n\n";

    int arr2[] = {11, 34, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "--- XET MANG 2 ---" << endl;

    cout << "Mang ban dau: ";
    inMang(arr2, n2);

    cout << "\n--> TAO DONG BAN DAU:\n";
    taoDongBanDau(arr2, n2);

    cout << "\n--> SAP XEP HEAP SORT:\n";
    sapXepHeap(arr2, n2);

    cout << "\nMang sau khi sap xep: ";
    inMang(arr2, n2);

    return 0;
}
