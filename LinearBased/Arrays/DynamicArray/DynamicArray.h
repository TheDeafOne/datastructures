// -lstdc++
#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray {
    private:
        // growth factor for expand method
        static const int GROWTH_FACTOR = 2; // some use 1.5 or the golden ratio

        // actual array size
        int array_size;
        
        // user array size and index of current array index for add method
        int add_index;

        // array of integers
        int* array;

        /**
         * @brief expand array based on GROWTH_FACTOR once the end of the current array is reached
         * this is for easier and faster memory access
         * 
         */
        void expand();
        
    public:
        /**
         * @brief Construct a new Dynamic Array object
         * 
         */
        DynamicArray();

        /**
         * @brief gets the value from the array at the given index
         * 
         * @param idx given index 
         * @return int value gotten from array at the given index
         */
        int get(int idx);

        /**
         * @brief sets the value at the given index in the array to the given value
         * 
         * @param idx given index
         * @param value int value to replace value in array
         */
        void set(int idx, int value);

        /**
         * @brief adds a given value to the end of the array
         * 
         * @param value int value to be added to the array
         */
        void add(int value);

        /**
         * @brief inserts a given value at a given index
         * 
         * @param idx index to place value
         * @param value int value to be added to the array
         */
        void insert(int idx, int value);
        
        /**
         * @brief removes a value from an array given an index
         * 
         * @param idx index to remove value at
         * @return int value that was removed
         */
        int remove(int idx);

        /**
         * @brief return size of user array size (not actual array size)
         * 
         * @return int size user array
         */
        int size() { return add_index; }
};

#endif