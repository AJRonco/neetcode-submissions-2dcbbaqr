class DynamicArray {
private:
    int* dynamicArray;
    int current_capacity;
    int length;
    

public:
    
    DynamicArray(int capacity) {
        current_capacity = capacity;
        length = 0;
        dynamicArray = new int[capacity];
    }

    int get(int i) {
        return dynamicArray[i];
    }

    void set(int i, int n) {

        dynamicArray[i] = n;

    }

    void pushback(int n) {
        if (length==current_capacity) {
            resize();
        }
        dynamicArray[length] = n;
        length++;
    }

    int popback() {
        if (length > 0 ) {
            length--;
        }
        return dynamicArray[length];

    }

    void resize() {
        current_capacity*=2;
        int* newArr = new int[current_capacity];

        for (int i = 0; i < length; i++) {
            newArr[i] = dynamicArray[i];
        }
        delete[] dynamicArray;
        dynamicArray = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return current_capacity;

    }
};
