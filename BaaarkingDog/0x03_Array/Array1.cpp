#include <bits/stdc++.h>
#define endl "\n"

// endl은 개행문자를 출력할 뿐아니라 출력 버퍼를 비우는 일까지 수행. 이는 매우 느린 작업이므로 PS시 불리

using namespace std;

void insert(int idx, int num, int arr[], int& len);
void erase(int idx, int arr[], int& len);
void printArr(int arr[], int& len) {
    for(int i = 0; i < len; i++) cout << arr[i] << ' ';
    cout << endl << endl;
}

int main() {
    // sync_with_stdio가 True일 경우 iostream(C++)과 stdio(C) 헤더의 버퍼를 모두 사용하기에 딜레이 발생 -> False로 설정
    ios::sync_with_stdio(0);

    // cin과 cout은 기본적으로 묶여있어 cin으로 입력받을 때 출력 버퍼를 먼저 비우는데, PS할 때 필요 없으므로 묶음을 풀어줌
    cin.tie(0);

    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    insert(3, 60, arr, len);
    printArr(arr, len);

    erase(4, arr, len);
    printArr(arr, len);

    return 0;
}

// O(N)
void insert(int idx, int num, int arr[], int& len) {
    len++;
    for(int i = len - 1; i > idx; i--) arr[i] = arr[i - 1]; // i >= idx로 하면 idx가 0인 경우 arr[i] = arr[i - 1]에서 오류 발생
    arr[idx] = num;
}

// O(N)
void erase(int idx, int arr[], int& len) {  
    // len--를 먼저하면 printArr 코드상 출력될 때 가려질뿐 len 범위 밖에 있는 원소들은 0이 아님.
    // lent--를 먼저하면 사실상 arr[] = {10, 50, 40, 60, 70, 20, 20, ... } 이상태지만 출력할 때는 10 50 40 60 70 20까지만 나옴 
    for(int i = idx; i < len; i++) arr[i] = arr[i + 1];
    len--;
}