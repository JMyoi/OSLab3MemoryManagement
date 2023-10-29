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
    p1.printInfo();
    p1.setJob(2);
    p1.setSize(50);
    p1.printInfo();
    Partition p2(20);
    p2.printInfo();
    cout<<p2.getPartitionId()<<endl<<p2.getSize()<<endl;
    

    //ask for user to input the number of jobs and the size of each job
    //ask the user for th enumber of partitions and the size of each partition

    //run the data through all algorithms and display it nicely.
    return 0;
}