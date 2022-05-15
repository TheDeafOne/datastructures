// -lstdc++
#include <string>
#ifndef OFILE_H_
#define OFILE_H_
class BitArray {
    private:
        /**
         * @brief Expand the array
         * given an index, expand the array accordingly regardless of bit index
         * 
         * @param ind index of array where required bit is stored
         */
        void expand(int ind);

        // current size of array
        size_t size = 128;
        /**
         * @brief int array, where each int is 4 bits
         * Array begins at 512 bits (128 ints) and is expanded from there
         */
        int array[128];

    public:
        /**
         * @brief Construct a new Bit Array object
         * sets up an empty array of size=128 (meaning 512 inital bits)
         */
        BitArray();

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
         * @brief Return array as a string
         * 
         * @return std::string string representation of the full bit array
         */
        std::string toString();

        /**
         * @brief returns size of bit array (not array)
         * ints in c++ are generally 4 bits, so the array size is multiplied by 4 to get actual size of bit array
         * 
         * @return int size of bit array 
         */
        int size() { return size * 4; };
};

#endif