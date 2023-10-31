#pragma once
#include "Job.h"
#include "Partition.h"
#include <vector>


    void firstFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void bestFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void nextFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    // void worstFit(vector<Partition>& mainMemory, vector<Job>& jobList);
    void outputInfo(vector<Partition>& mainMemory, vector<Job>& jobList);
    
