#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    dat[unused] = num;          // 비어있는 주소에 값 할당
    pre[unused] = addr;         // 새로 할당한 곳의 pre를 insert 대상 주소 addr과 연결
    nxt[unused] = nxt[addr];    // 새로 할당한 곳의 nxt를 insert 대상의 nxt와 연결

    if(nxt[addr] != -1) pre[nxt[addr]] = unused;    // 기존 addr의 nxt의 pre는 기존에 비어있던 주소와 연결 단, nxt[addr]이 -1이 아닌 경우에만.
    nxt[addr] = unused;         // 기존 addr의 nxt는 기존에 비어있던 주소와 연결, 만약 14번줄의 코드가 13번보다 먼저 실행되면 자기자신과 연결되어버림림

    unused++;                   // 다음 할당에 쓰일 비어있는 주소 갱신신
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr]; // pre[addr]은 dummy node (0)의 존재로 인해 예외가 발생할 경우가 없음음
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; // 기존 위치의 다음 위치가 끝부분이었다면 -1이 들어 올 수 있기에 이에 대한 예외처리
}

void traverse() {
    int cur = nxt[0];
    while(cur != -1){
      cout << dat[cur] << ' ';
      cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
  traverse();
}

int main(void) {
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    insert_test();
    erase_test();
}