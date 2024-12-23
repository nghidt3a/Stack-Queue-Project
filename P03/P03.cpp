// ===============================
// 2.3 Queue as an Array
// ===============================
struct Queue {
    int* data; // Mảng động để lưu trữ các phần tử trong hàng đợi
    int in;    // Chỉ số để thêm phần tử mới
    int out;   // Chỉ số để lấy phần tử ra
    int capacity; // Dung lượng tối đa của hàng đợi
};

void init(Queue& q, int capacity) {
    q.data = new int[capacity]; // Cấp phát bộ nhớ cho mảng động
    q.in = 0; // Đặt vị trí thêm phần tử ban đầu
    q.out = 0; // Đặt vị trí lấy phần tử ban đầu
    q.capacity = capacity; // Gán dung lượng tối đa cho hàng đợi
}

bool enqueue(Queue& q, int x) {
    if ((q.in + 1) % q.capacity == q.out) return false; // Kiểm tra nếu hàng đợi đầy
    q.data[q.in] = x; // Thêm phần tử vào vị trí hiện tại
    q.in = (q.in + 1) % q.capacity; // Cập nhật chỉ số thêm phần tử
    return true;
}

bool dequeue(Queue& q, int& value) {
    if (q.in == q.out) return false; // Kiểm tra nếu hàng đợi rỗng
    value = q.data[q.out]; // Lấy giá trị phần tử tại vị trí lấy ra
    q.out = (q.out + 1) % q.capacity; // Cập nhật chỉ số lấy phần tử
    return true;
}

bool isEmpty(const Queue& q) {
    return q.in == q.out; // Trả về true nếu hàng đợi rỗng
}

void empty(Queue& q) {
    q.in = q.out = 0; // Đặt hàng đợi về trạng thái rỗng
}

int size(const Queue& q) {
    return (q.in - q.out + q.capacity) % q.capacity; // Tính số lượng phần tử trong hàng đợi
}

