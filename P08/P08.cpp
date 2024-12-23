
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q; // Tạo queue rỗng
    q.push(5); // Thêm 5
    q.push(10); // Thêm 10
    cout << "Phan tu dau tien: " << q.front() << endl;
    q.pop(); // Xóa phần tử đầu
    cout << "Phan tu dau sau khi xoa: " << q.front() << endl;
    return 0;
}
