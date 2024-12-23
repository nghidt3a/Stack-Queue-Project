
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s; // Tạo stack rỗng
    s.push(1); // Thêm 1
    s.push(2); // Thêm 2
    cout << "Phan tu dau: " << s.top() << endl; // Truy cập
    s.pop(); // Xóa phần tử đầu
    cout << "Phan tu dau sau khi xoa: " << s.top() << endl;
    return 0;
}
