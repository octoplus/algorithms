#include<bits/stdc++.h>

using namespace std;

bool is_prime(int num) {
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

int main(){
    cout<<is_prime(1991)<<endl;
    return 0;
}