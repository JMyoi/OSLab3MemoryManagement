#pragma once
#include "Job.h"
#include "Partition.h"
#include <vector>

class Algorithms{
    public:
    void bestFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void firstFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void nextFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void worstFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    
    private:

};