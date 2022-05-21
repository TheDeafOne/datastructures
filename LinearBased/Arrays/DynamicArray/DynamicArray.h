// -lstdc++
#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray {
    private:
        const int GROWTH_FACTOR = 2; // some use 1.5
        int array_size;
        int add_index;
        int* array;
        void expand();
        
    public:
        DynamicArray();
        int get(int idx);
        void set(int idx, int value);
        void add(int value);
        void insert(int idx, int value);
        int remove(int idx);
};

#endif