
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // Tạo vecto rỗng
    v.push_back(10); // Thêm 10
    v.push_back(20); // Thêm 20
    cout << "Phan tu dau tien: " << v[0] << endl; // Truy cập
    v.pop_back(); // Xóa phần tử cuối
    cout << "Kich thuoc vector: " << v.size() << endl; // Kich thước
    return 0;
}

