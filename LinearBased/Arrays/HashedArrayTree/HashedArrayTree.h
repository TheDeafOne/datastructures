// -lstdc++
#ifndef HASHEDARRAYTREE_H_
#define HASHEDARRAYTREE_H_

class HashedArrayTree {
    private:
        // size of array from end to end
        int root_size;
        // root array containing leaf arrays
        int** root_array;
        // index at which next leaf array will be added
        int leaf_index;
        // next index to add given value
        int add_index;
        
        /**
         * @brief make the root array larger
         * 
         */
        void expand();

        /**
         * @brief make a new leaf array and add it to the next available spot on the root array
         * 
         */
        void newLeaf();

    public:
        /**
         * @brief Construct a new Hashed Array Tree object
         * 
         */
        HashedArrayTree();

        /**
         * @brief get a value from the array using the given index
         * 
         * @param idx the index at which to find the value
         * @return int the value found in the array at idx
         */
        int get(int idx);

        /**
         * @brief set the old value at the given index in the array to the new given value
         * 
         * @param idx index at which to change the value
         * @param value new value to replace the old one
         * @return int old value that was replaced
         */
        int set(int idx, int value);

        /**
         * @brief add the given value to the next available spot in the array
         * 
         * @param value value to be added to the array
         */
        void add(int value);
        
        /**
         * @brief insert the given value at the given index
         * 
         * @param idx index at which to insert the given value
         * @param value being inserted
         */
        void insert(int idx, int value);

        /**
         * @brief remove the value at the given index
         * 
         * @param idx index in the array at which the value should be removed
         * @return int value being removed
         */
        int remove(int idx);

        /**
         * @brief return the size of the array according to the user view
         * 
         * @return int size of the array
         */
        int size() { return add_index; }

        /**
         * @brief return the root size of the array
         * 
         * @return int root size of the array
         */
        int rootSize() { return root_size; }
};

#endif