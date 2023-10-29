#pragma once 
#include <string>
using namespace std;

class Job{
    public:
        Job();
        Job(int size);
        void printInfo();
        void setPartition(int partitionId);
        int getJobId();
        int getSize();


    private:

        int id;
        int partitionId;//the partition it is assigned to if none then null
        int size;
        string jobState;


};