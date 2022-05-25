// -lstdc++
#ifndef HASHEDARRAYTREE_H_
#define HASHEDARRAYTREE_H_

class HashedArrayTree {
    private:
        // size of array from end to end
        int array_size;
        int root_size;
        // current power of 2 that root array is at
        int power;
        // root array containing leaf arrays
        int** root_array;
        // index at which next leaf array will be added
        int leaf_index;
        // next index to add given value
        int add_index;
                
        void expand();

        void newLeaf();

    public:
       HashedArrayTree();

       int get(int idx);

       int set(int idx, int value);

       void add(int value);
       
       void insert(int idx, int value);

       int remove(int idx);

       int size() { return add_index; }

       int rootSize() { return root_size; }

       
};

#endif