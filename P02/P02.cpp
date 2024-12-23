

#include <iostream>
using namespace std;

struct Node {
	int data; // Giá trị của nút
	Node* next; // Con trỏ trỏ đến nút tiếp theo
};

struct LinkedStack {
	Node* head; // Con trỏ đầu của stack (đỉnh stack)
	int capacity; // Số lượng phần tử hiện tại trong stack
};

void init(LinkedStack& s) {
	s.head = nullptr; // Đặt stack rỗng ban đầu
	s.capacity = 0; // Gán số lượng phần tử ban đầu là 0
}

bool push(LinkedStack& s, int x) {
	Node* newNode = new Node; // Tạo nút mới
	newNode->data = x; // Gán giá trị cho nút mới
	newNode->next = s.head;
	s.head = newNode; // Cập nhật đỉnh stack
	s.capacity++; // Tăng số lượng phần tử
	return true;
}

bool pop(LinkedStack& s, int& value) {
	if (!s.head) return false; // Kiểm tra nếu stack rỗng
	Node* temp = s.head; // Lưu con trỏ tạm thời đến nút đỉnh
	value = temp->data; // Lấy giá trị của nút đỉnh 
	s.head = s.head->next; // Cập nhật đỉnh stack
	delete temp; // Giải phóng bộ nhớ của nút cũ
	s.capacity--; // Giảm số lượng phần tử
	return true;
}

bool isEmpty(LinkedStack& s) {
	return s.head == nullptr; // Trả về true nếu stack rỗng
}

void empty(LinkedStack& s) {
	while (s.head) { // Lapwh qua các nút và xóa từng nút
		Node* temp = s.head;
		s.head = s.head->next;
		delete temp;
	}
	s.capacity = 0; // Đặt số lượng phần tử về 0
}

int size(LinkedStack& s) {
	return s.capacity; // Trả về số lượng phần tử
}