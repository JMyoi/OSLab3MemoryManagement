#pragma once
#include <string>
using namespace std;

class Partition{
    public:
        Partition();
        Partition(int size);
        void setJob(int jobId);
        void setSize(int size); 
        void setWaste(int w);
        int getPartitionId();
        int getSize();
        int getWaste();
        void printInfo();
        bool Used();


    private:
        static int nextId;
        int id;//a valid id is >=0
        bool inUse;
        int jobId;//the process it is assigned to if none zet to null
        int size;
        int waste;


};