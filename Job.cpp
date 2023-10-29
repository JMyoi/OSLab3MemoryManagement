#include "Job.h"
#include <iostream>
using namespace std;

int Job::nextId = 0;

Job::Job(){
    id = nextId++;
    partitionId = -1;
    size = 0;
    jobState = "wait";
}

Job::Job(int size){
    id = nextId++;
    partitionId = -1;
    this->size = size;
    jobState = "wait";
}

void Job::setPartition(int partitionId){
    this->partitionId = partitionId;
    jobState = "run";
}

int Job::getJobId(){
    return id;
}

void Job::printInfo(){
    cout<<"\nid: "<<id<<"\nsize: "<< size<<"\npartitionId: "<<partitionId<<"\nState: "<< jobState<<endl;
}
