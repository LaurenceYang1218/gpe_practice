#include <iostream>
#include <vector>
using namespace std;

long long reverse_ll(long long init){
    long long result = 0;
    while(init != 0){
        result = 10 * result + (init % 10);
        init /= 10;
    }
    return result;
}
bool isPalindrome(long long init){
    return init == reverse_ll(init);
}
int main() {
    int n;
    cin >> n;
    long long cnt, init, rev_init;
    while(n--){
        cnt = 1;
        cin >> init;
        while(true){
            rev_init = reverse_ll(init);
            init += rev_init;
            if(isPalindrome(init)){
                cout << cnt << " " << init << '\n';
                break;
            }
            cnt++;
        }
    }
    return 0;
}