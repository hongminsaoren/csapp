#define _GNU_SOURCE
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include "cachelab.h"

typedef struct {
    int valid;
    int tag;
    int time;
} CacheLine;
CacheLine **cache;

int hitCount, missCount, evictionCount;
int s, S, E, b;
char *traceFile;

void mallocCache(){
    cache = (CacheLine **)malloc(sizeof(CacheLine *) * S);
    assert(cache);
    for(int i = 0; i < S; i++) {
        cache[i] = (CacheLine *)calloc(E, sizeof(CacheLine));
        assert(cache[i]);
    }
}

void freeCache(){
    for(int i = 0; i < S; i++) {
        free(cache[i]);
    }
    free(cache);
}

void accessAt(unsigned addr){
    int setIndex = (addr >> b) & ((1 << s) - 1);
    int tag = addr >> (s + b);
    CacheLine *cacheSet = cache[setIndex];

    for (int i = 0; i < E; i++) {
        if(cacheSet[i].valid && cacheSet[i].tag == tag) {
            cacheSet[i].time = 0;
            hitCount++;
            return;
        }
    }
    
    missCount++;
    for(int i = 0; i < E; i++) {
        if(!cacheSet[i].valid) {
            cacheSet[i].valid = 1;
            cacheSet[i].tag = tag;
            cacheSet[i].time = 0;
            return;
        }
    }

    evictionCount++;
    int maxTime = 0;
    int maxTimeIndex = 0;
    for(int i = 0; i < E; i++) {
        if(cacheSet[i].time > maxTime) {
            maxTime = cacheSet[i].time;
            maxTimeIndex = i;
        }
    }
    // cacheSet[maxTimeIndex].valid = 1; // already valid
    cacheSet[maxTimeIndex].tag = tag;
    cacheSet[maxTimeIndex].time = 0;
}

void simulateCache(){
    FILE *fp = fopen(traceFile, "r");
    assert(fp);

    char op;
    unsigned addr;
    int size;
    while(fscanf(fp, " %c %x,%d", &op, &addr, &size) != EOF) {
        if(op == 'I') {
            continue;
        } else if (op == 'L' || op == 'S') {
            accessAt(addr);
        } else {
            accessAt(addr);
            accessAt(addr);
        }

        // LRU update
        for(int i = 0; i < S; i++) {
            for(int j = 0; j < E; j++) {
                if(cache[i][j].valid) {
                    cache[i][j].time++;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int opt;
    while((opt = getopt(argc, argv, "s:E:b:t:")) != -1) {
        switch(opt) {
            case 's':
                s = atoi(optarg);
                S = 1 << s;
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                traceFile = optarg;
                break;
            default:
                printf("Wrong argument!\n");
                exit(1);
        }
    }
    mallocCache();
    simulateCache();
    freeCache();

    printSummary(hitCount, missCount, evictionCount);
    return 0;
}
