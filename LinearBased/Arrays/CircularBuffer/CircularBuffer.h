// -lstdc++
#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

class CircularBuffer {
    private:
        // array size
        size_t buffer_size;

        // buffer
        int* buffer;

        // reader and writer (sometimes referred to as start and end respectively)
        int reader = 0;
        int writer = 0;

    public:
        /**
         * @brief Construct a new Circular Buffer object
         * 
         * @param size length of buffer
         */
        CircularBuffer(size_t size);

        /**
         * @brief set the current write index to a given value
         * 
         * @param value given int to add to buffer
         */
        void write(int value);

        /**
         * @brief read the int at the current read index
         * 
         * @return int value at read index
         */
        int read();

        /**
         * @brief returns size of buffer
         * 
         * @return size_t size of buffer
         */
        size_t size() { return buffer_size; }
};

#endif