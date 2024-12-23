
#include <iostream>
using namespace std;

struct Stack {
	int* data; // Mảng động để lưu trữ các phần tử trong stack
	int top; // Chỉ số của phần tử trên cùng trong stack
	int capacity; // Dung lượng tối đa của stack
};

void init(Stack& s, int capacity) {
	s.capacity = capacity; // Gán dung lượng tối đa cho stack
	s.data = new int[capacity]; // Cấp phát bộ nhớ cho mảng động
	s.top = -1; // Đặt chỉ số phần tử trên cùng là -1 (stack rỗng)
}

bool push(Stack& s, int x) {
	if (s.top == s.capacity - 1) {
		cout << "Stack overflow!" << endl; // Kiểm tra nếu stack đầy
		return false;
	}
	s.data[++s.top] = x; // Tăng chỉ số và thêm phần tử vào stack
	return true;
}

bool pop(Stack& s, int& value) {
	if (s.top == -1) {
		cout << "Stack underflow!" << endl; // Kiểm tra nếu stack rỗng
		return false; 
	}
	value = s.data[s.top--]; // Lấy giá trị phần tử trên cùng và giảm chỉ số
	return true;
}

bool isEmpty(Stack s) {
	return s.top == -1; // Trả về true nếu stack rỗng
}

void empty(Stack& s) {
	s.top = -1; // Đặt lại stack về trạng thái rỗng
}

int size(Stack s) {
	return s.top - 1; // Trả về số lượng phần tử trong stack
}



