#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n;

    cin >> n;

    int area = n * n;

    if (n >= 5) {
        cout << area;
    } else {
        cout << area << endl;
        cout << "tiny";
    }

    return 0;
}