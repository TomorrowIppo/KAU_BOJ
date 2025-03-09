#include <bits/stdc++.h>
using namespace std;

// push_back, pop_back O(1)
// push_front, pop_front O(N) 단, vector에는 없는 없음

int main(void) {
  vector<int> v1(3, 5); // {5,5,5};
  cout << v1.size() << '\n'; // 3
  v1.push_back(7); // {5,5,5,7};

  vector<int> v2(2); // {0,0};
  v2.insert(v2.begin()+1, 3); // {0,3,0}; O(N)

  vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
  v3.erase(v3.begin()+2); // {1,2,4}; O(N)

  vector<int> v4; // {}
  v4 = v3; // {1,2,4} deep copy
  cout << v4[0] << v4[1] << v4[2] << '\n';
  v4.pop_back(); // {1,2}
  v4.clear(); // {}
}

/*

vector v1 = {1, 2, 3, 4, 5};

// range-based for loop
for(auto e : v1)
    cout << e << ' ';

// not bad
for(int i = 0; i < v1.size(); i++)
    cout << v1[i] <<  ' ';

// ****** WRONG ******
for(int i = 0; i <= v1.size() - 1; i++)
    cout << v1[i] << ' ';

기본적으로 vector의 size 메소드는 unsigned int 형태의 값을 반환하는데, 여기에 -1을 해버리면
unsigned int와 int의 연산이 되는데, 이때 자동으로 unsigned int 혹은 unsigned long long으로 형변환된다. 
만약 v1이 빈 벡터였다면 언더플로우가 발생하게되어 해당 결과값은 -1이 아닌 4294967295가 되어버린다.

*/