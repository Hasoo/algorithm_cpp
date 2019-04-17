#include <iostream>

class CircleQue {
   private:
    struct Que {
        int32_t front;
        int32_t rear;
        int32_t size;
        int32_t* data;
    };

    Que* que_ = NULL;

    const int32_t kInitValue = -1;

    CircleQue() {}

   public:
    CircleQue(const int32_t size) {
        que_ = reinterpret_cast<Que*>(malloc(sizeof(Que)));
        que_->front = que_->rear = kInitValue;
        que_->size = size;
        que_->data =
            reinterpret_cast<int32_t*>(malloc(que_->size * sizeof(int32_t)));
    }
    ~CircleQue() {
        free(que_->data);
        free(que_);
    }

    bool empty() {
        if (kInitValue == que_->front) return true;
        return false;
    }

    bool full() {
        if (que_->front == (que_->rear + 1) % que_->size) return true;
        return false;
    }

    int32_t size() {
        if (empty()) return 0;
        return (que_->size - que_->front + que_->rear + 1) % que_->size;
    }

    bool push(const int32_t value) {
        if (full()) return false;
        que_->rear = (que_->rear + 1) % que_->size;
        que_->data[que_->rear] = value;
        if (kInitValue == que_->front) {
            que_->front = que_->rear;
        }
        return true;
    }

    int32_t pop() {
        int value = 0;
        if (empty()) return value;
        value = que_->data[que_->front];
        if (que_->front == que_->rear) {
            que_->front = que_->rear = kInitValue;
        } else {
            que_->front = (que_->front + 1) % que_->size;
        }
        return value;
    }
};