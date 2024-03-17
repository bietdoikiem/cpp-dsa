#include <bits/stdc++.h>

using namespace std;

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return ((long long)x.first)^(((long long)x.second)<<32);
  }
};

int main() {
    return 0;
}