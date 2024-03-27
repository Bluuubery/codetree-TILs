#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.

    int score;
    cin >> score;

    string pf = score == 100 ? "pass" : "failure";

    cout << pf;
    return 0;
}