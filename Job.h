#pragma once 
#include <string>
using namespace std;

class Job{
    public:
        Job();
        Job(int size);
        void setPartition(int partitionId);
        int getJobId();
        int getSize();
        void printInfo();
        int getPartitionId();
        int getWaste();
        void setWaste(int w);


    private:
        static int nextId;
        int id;
        int waste;
        int partitionId;//the partition it is assigned to if none then null
        int size;
        string jobState;


};