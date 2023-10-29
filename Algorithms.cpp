#include "Algorithms.h"
#include "Job.h"
#include "Partition.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

   void firstFit(vector<Partition>& mainMemory, vector<Job>& jobList){
        jobList.at(0).setPartition(3);
        jobList.at(0).printInfo();
        mainMemory.at(0).setJob(3);
        mainMemory.at(0).printInfo();
   }