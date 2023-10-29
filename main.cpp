#include <iostream>
#include <vector>
#include "Job.h"
#include "Partition.h"
#include "Algorithms.h"

using namespace std;

int main(){

    //create vector of jobs and call it job list
    vector<Job> jobList;
    //create vector of partitions and call it main memory
    vector<Partition> mainMemory;
    Partition p1(100);
    p1.setJob(2);
    p1.setSize(50);
    Partition p2(20);
    mainMemory.push_back(p1);
    mainMemory.push_back(p2);
    jobList.size();
    for(int i = 0; i<mainMemory.size();i++){
        mainMemory.at(i).printInfo();
    }
    cout<<endl<<"*******************************************";

    Job j1(20);
    Job j2(30);
    jobList.push_back(j1);
    jobList.push_back(j2);
    for(int i = 0; i<jobList.size(); i++){
        jobList.at(i).printInfo();
    }
    

    //ask for user to input the number of jobs and the size of each job
    //ask the user for th enumber of partitions and the size of each partition

    //run the data through all algorithms and display it nicely.
    return 0;
}