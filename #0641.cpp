class MyCircularDeque
{
    vector<int> dq;
    int cursize, front, rear, n;

public:
    MyCircularDeque(int k)
    {
        dq.resize(k);
        cursize = 0;
        front = -1;
        rear = -1;
        n = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + n) % n;
        dq[front] = value;
        cursize++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % n;
        dq[rear] = value;
        cursize++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % n;
        cursize--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + n) % n;
        cursize--;
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : dq[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : dq[rear];
    }

    bool isEmpty()
    {
        return cursize == 0;
    }

    bool isFull()
    {
        return cursize == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */