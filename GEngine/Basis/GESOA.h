#ifndef GESOA_H
#define GESOA_H

namespace ge {
    const int soa_chunk_size = 2048;
    const int soa_query_max_size = 512;
    const int soa_block_size = 15;
    const int soa_chunk_inc = 64;

    struct memBlock {
        memBlock* next;
    };

    struct memChunk {
        int blockSize;
        memBlock* blocks;
    };

    class SmallObjectAllocator {
    public:
    
        SmallObjectAllocator();
        ~SmallObjectAllocator();

        void* allocate(int size);
        void free(void* mem, int size);
        void destroy();
    
    private:
        memChunk* chunks;
        int chunkSpace;
        int chunkCount;

        memBlock* soaFreeLists[soa_block_size];
        static int blockSizes[soa_block_size];
        static char blockSizeBucket[soa_query_max_size + 1];
        static bool blockSizeBucketInit;
    };
}


#endif