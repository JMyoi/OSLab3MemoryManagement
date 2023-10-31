#include "Partition.h"
#include <iostream>
using namespace std;

int Partition::nextId = 0;

Partition::Partition(){
    size = 0;
    id = nextId++;
    jobId = -1;
    inUse = false;
    waste = 0;
}
Partition::Partition(int size){
    this->size = size;
    id = nextId++;
    jobId = -1;
    inUse = false;
    waste = 0;

}
void Partition::setJob(int jobId){
    this->jobId = jobId;
    inUse = true;
}
void Partition::setSize(int size){
    this->size = size;
}
int Partition::getPartitionId(){
    return id;
}
int Partition::getSize(){
    return size;
}
void Partition::setWaste(int w){
    waste = w;
}
void Partition::printInfo(){
    cout << "\nPartition ID: "<<id<<"\nsize: "<<size<<"\nIn Use:"<<inUse<<"\nJob ID: "<<jobId<<"\nwaste: "<<waste<<endl;
}