#include "queue.h"
#include "Shared_ptr.h"

class MyQueue : public Queue {
public:
    explicit MyQueue(long long _data) : Queue(_data) {}

    MyQueue() : Queue() {}

    void make_task() {
        auto uniqueElements = new long long[size()][2];
        auto count = 0;
        Shared_ptr<Node> _tmp = front;
        while (_tmp.operator->() != nullptr) {
            bool isAdded = false;
            for (int i = 0; i < count; i++) {
                if (_tmp->data == uniqueElements[i][0]) {
                    uniqueElements[i][1]++;
                    isAdded = true;
                }
            }
            if (!isAdded) {
                uniqueElements[count][0] = _tmp->data;
                uniqueElements[count][1] = 1;
                count++;
            }
            _tmp = _tmp->next;
        }

        _tmp = front;
        while (_tmp.operator->() != nullptr) {
            Shared_ptr<Node> _tmp_next = _tmp->next;
            for (int i = 0; i < count; i++) {
                if (_tmp->data == uniqueElements[i][0] && uniqueElements[i][1] > 1) {
                    erase(_tmp);
                    break;
                }
            }
            _tmp = _tmp_next;
        }
    }

    void print() {
        Shared_ptr<Node> _tmp = front;
        while (_tmp.operator->() != nullptr) {
            std::cout << _tmp->data << "\n";
            _tmp = _tmp->next;
        }
    }
};