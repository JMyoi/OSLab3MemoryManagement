#include <iostream>
#include <vector>
#include "Job.h"
#include "Partition.h"
#include "Algorithms.h"

using namespace std;

int main(){

    vector<Job> jobList;
    vector<Partition> mainMemory;

    cout<<"Enter the number of jobs: ";
    int numJobs = 0;
    cin>>numJobs;
    for(int i = 0; i<numJobs; i++){
        int jobSize = 0;
        cout<<"Enter the size of job number "<<i+1<<": ";
        cin>>jobSize;
        Job currentJob(jobSize);
        jobList.push_back(currentJob);
    }
    // for(int i =0; i<jobList.size(); i++){
    //     jobList.at(i).printInfo();
    // }

    cout<<"Enter the number of partitions: ";
    int numPartitions = 0;
    cin>>numPartitions;
    for(int i =0; i<numPartitions; i++){
        int sizePartition = 0;
        cout<<"Enter the size of partition "<<i+1<<": ";
        cin>>sizePartition;
        Partition currentPartition(sizePartition);
        mainMemory.push_back(currentPartition);
    }
    // for(int i =0; i<mainMemory.size(); i++){
    //     mainMemory.at(i).printInfo();
    // }
    //always use new vector object when giving it to algorithms so that the manipulated data of 
    //an object from an algorithm does not pass on to others.
    cout<<"*******************************First-Fit******************************\n";
    vector<Job> FFjobList = jobList;
    vector<Partition> FFmainMemory = mainMemory;
    firstFit(FFmainMemory, FFjobList);
    cout<<"**********************************************************************\n";

    cout<<"*******************************Next-Fit*******************************\n";
    vector<Job> NFjobList = jobList;
    vector<Partition> NFmainMemory  = mainMemory;
    nextFit(NFmainMemory, NFjobList);
    cout<<"**********************************************************************\n";

    cout<<"*******************************Best-Fit*******************************\n";
    vector<Job> BFjobList = jobList;
    vector<Partition> BFmainMemory  = mainMemory;
    bestFit(BFmainMemory, BFjobList);
    cout<<"**********************************************************************\n";

    cout<<"*******************Worst-Fit(Dynamic parititons)**********************\n";

    cout<<"**********************************************************************\n";




    

    //run the data through all algorithms and display it nicely.
    return 0;
}

