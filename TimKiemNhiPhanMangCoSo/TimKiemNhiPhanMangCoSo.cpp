// TimKiemNhiPhanMangCoSo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void NhapMang(int M[], int n);
void XuatMang(int M[], int n);
int BinarySearch(int M[], int n, int x);
int BinarySearchRecur(int M[], int left, int right,int x);

int main()
{
    const int n = 5;
    int M[n];
    int x;

    NhapMang(M, n);
    cout << "Mang sau khi nhap: \n";
    XuatMang(M, n);
    cout << "\nNhap so muon tim: ";
    cin >> x;
    
    //int kq = BinarySearch(M, n, x);
    int kq = BinarySearchRecur(M, 0, n - 1, x);
    if (kq == -1)
        cout << "Khong thay " << x;
    else
        cout << "Tim thay " << x << " o vi tri M[" << kq << "]";
    return 0;
}

void NhapMang(int M[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "M[" << i << "]=";
        cin >> M[i];
    }
}

void XuatMang(int M[], int n)
{
    for (int i = 0; i < n; i++)
        cout << M[i] << "\t";
}

int BinarySearch(int M[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    do
    {
        mid = (left + right) / 2;
        if (x == M[mid])
            return mid;
        else
            if (x < M[mid])
                right = mid - 1;
            else
                left = mid + 1;
    } while (left <= right);
    return-1;
}

int BinarySearchRecur(int M[], int left, int right, int x)
{
    int mid = (left + right) / 2;
    if (left > right)
        return -1;
    if (M[mid] == x)
        return mid;
    else
        if (M[mid] > x)
            return BinarySearchRecur(M, mid + 1, right, x);
        else
            return BinarySearchRecur(M, left, mid - 1, x);
    return -1;
}


