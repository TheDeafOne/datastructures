// -lstdc++
#ifndef BITARRAY_H_
#define BITARRAY_H_

class BitArray {
    private:
        // current size of array
        size_t array_size;
        /**
         * @brief int array, where each int is 32 bits
         */
        int* array;


    public:
        /**
         * @brief Construct a new Bit Array object
         */
        BitArray(size_t size);

        /**
         * @brief Set a bit
         * given an index k, setBit finds the correct bit position and sets it
         * 
         * @param k index of bit to set
         */
        void setBit(int k);

        /**
         * @brief Clear a bit
         * given an index k, clearBit finds the correct bit possition and clears it
         * 
         * @param k index of bit to be cleared
         */
        void clearBit(int k);

        /**
         * @brief Test a bit
         * given an index, testBit finds the correct bit and tests its value
         * 
         * @param k index of bit to be tested
         * @return true if bit is 1
         * @return false if bit is 0
         */
        bool testBit(int k);

        /**
         * @brief returns size of bit array (not array)
         * ints in c++ are 32 bits, so the array size is multiplied by 32 to get actual size of bit array
         * 
         * @return int size of bit array 
         */
        size_t size() { return array_size * 32; };
};

#endif