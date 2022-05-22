// -lstdc++
#ifndef GAPBUFFER_H_
#define GAPBUFFER_H_

class GapBuffer {
    private:
        static const int GROWTH_FACTOR = 2;
        char* buffer;
        int buffer_size;
        int gap_size;
        
    public:
       int bufferSize();
       int gapSize();
       
};

#endif