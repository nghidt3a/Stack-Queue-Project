// ===============================
// 2.4 Queue as a Linked List
// ===============================


#include <iostream>
using namespace std;

struct Node {
    int data; // Giá trị của nút
    Node* next; // Con trỏ trỏ đến nút tiếp theo
};

struct LinkedQueue {
    Node* head; // Con trỏ đến đầu hàng đợi
    Node* tail; // Con trỏ đến cuối hàng đợi
    int capacity; // Số lượng phần tử hiện tại trong hàng đợi
};

void init(LinkedQueue& q) {
    q.head = nullptr; // Đặt hàng đợi rỗng ban đầu
    q.tail = nullptr; // Không có phần tử cuối
    q.capacity = 0;   // Gán số lượng phần tử ban đầu là 0
}

bool enqueue(LinkedQueue& q, int x) {
    Node* newNode = new Node; // Tạo nút mới
    newNode->data = x; // Gán giá trị cho nút mới
    newNode->next = nullptr; // Nút mới sẽ không trỏ đến nút nào
    if (!q.head) { // Nếu hàng đợi rỗng
        q.head = q.tail = newNode; // Cả đầu và cuối đều trỏ đến nút mới
    }
    else {
        q.tail->next = newNode; // Thêm nút mới vào cuối hàng đợi
        q.tail = newNode; // Cập nhật nút cuối
    }
    q.capacity++; // Tăng số lượng phần tử
    return true;
}

bool dequeue(LinkedQueue& q, int& value) {
    if (!q.head) return false; // Kiểm tra nếu hàng đợi rỗng
    Node* temp = q.head; // Lưu con trỏ tạm thời đến nút đầu
    value = temp->data; // Lấy giá trị của nút đầu
    q.head = q.head->next; // Cập nhật đầu hàng đợi
    if (!q.head) q.tail = nullptr; // Nếu hàng đợi rỗng sau khi xóa
    delete temp; // Giải phóng bộ nhớ của nút cũ
    q.capacity--; // Giảm số lượng phần tử
    return true;
}

bool isEmpty(const LinkedQueue& q) {
    return q.head == nullptr; // Trả về true nếu hàng đợi rỗng
}

void empty(LinkedQueue& q) {
    while (q.head) { // Lặp qua các nút và xóa từng nút
        Node* temp = q.head;
        q.head = q.head->next;
        delete temp;
    }
    q.tail = nullptr; // Không còn phần tử nào trong hàng đợi
    q.capacity = 0;   // Đặt số lượng phần tử về 0
}

int size(const LinkedQueue& q) {
    return q.capacity; // Trả về số lượng phần tử hiện tại
}
