/*

주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면
1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
arr의 각 수는 0 이상 100 이하이고 N은 1000 이하이다.

시간복잡도 O(N)인 로직을 작성하시오.

*/

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int func2(int arr[], int N) {
    bool vis_num[1001] = {};
    for(int i = 0; i < N; i++)
    {
        if(vis_num[100 - arr[i]]) return 1;
        else vis_num[arr[i]] = true;
    }

    return 0;
}

void printResult(int arr[], int N) {
    cout << func2(arr, N) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr1[3] = {1, 52, 48};
    int arr2[2] = {50, 42};
    int arr3[4] = {4, 13, 63, 87};

    printResult(arr1, 3);
    printResult(arr2, 2);
    printResult(arr3, 4);

    return 0;
}