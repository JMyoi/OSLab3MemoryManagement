#include "Job.h"
#include <iostream>
using namespace std;

int Job::nextId = 1;

Job::Job(){
    id = nextId++;
    partitionId = -1;
    size = 0;
    jobState = "wait";
    waste =0;
}

Job::Job(int size){
    id = nextId++;
    partitionId = -1;
    this->size = size;
    jobState = "wait";
    waste =0;
}
void Job::setWaste(int w){
    waste = w;
}
int Job::getWaste(){
    return waste;
}
void Job::setPartition(int partitionId){
    this->partitionId = partitionId;
    jobState = "run";
}

int Job::getJobId(){
    return id;
}
int Job::getPartitionId(){
    return partitionId;
}
int Job::getSize(){
    return size;
}



void Job::printInfo(){
    cout<<"Job ID: "<<id<<"partition Id: "<<partitionId<<"State: "<< jobState;
}
