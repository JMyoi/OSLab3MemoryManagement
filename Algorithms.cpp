#include "Algorithms.h"
#include "Job.h"
#include "Partition.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

     void outputInfo(vector<Partition>& mainMemory, vector<Job>& jobList){
          cout<<"Job Id"<<setw(16)<<"PartitionId"<<setw(10)<<"State"<<setw(10)<<"waste"<<endl;
          for(int i= 0; i<jobList.size(); i++){
               jobList.at(i).printInfo();
               cout<<setw(9)<<jobList.at(i).getWaste()<<endl;
          }
          int totalWaste =0;
          for(int i = 0; i<jobList.size();i++){
               totalWaste+=jobList.at(i).getWaste();
          }
          cout<<"Total Waste = "<<totalWaste<<endl;
     }

   void firstFit(vector<Partition>& mainMemory, vector<Job>& jobList){

          for(int i = 0; i<jobList.size(); i++){

               for(int j = 0; j<mainMemory.size(); j++){

                    if(jobList.at(i).getSize()<=mainMemory.at(j).getSize() ){
                         //if the partition is not in use 
                         if(!mainMemory.at(j).Used()){
                              //set the job to that partition
                              mainMemory.at(j).setJob(jobList.at(i).getJobId());
                              //set the partition to that job
                              jobList.at(i).setPartition(mainMemory.at(j).getPartitionId());
                              //set the waste of the partition 
                              mainMemory.at(j).setWaste(mainMemory.at(j).getSize() - jobList.at(i).getSize());
                              jobList.at(i).setWaste(mainMemory.at(j).getSize() - jobList.at(i).getSize());
                              break;//break out of the inner for loop and continue on with the next job
                         }
                    }

               }

          }
          outputInfo(mainMemory, jobList);

   }

void nextFit(vector<Partition>& mainMemory, vector<Job>& jobList){
     //keep track of last index to continue with
     int lastIndex = 0;

     for(int i = 0; i<jobList.size();i++){
          //keep track to see if a job has checked all partitions.
          //increment the number of partition the current job has checked.


          for( int numPartitionsChecked =0; numPartitionsChecked < mainMemory.size(); numPartitionsChecked++, lastIndex++){


               //checks to see if it is out of bound if it is reset it to zero.
               if(lastIndex == mainMemory.size()){
                    lastIndex = 0;
               }

               if(jobList.at(i).getSize()<=mainMemory.at(lastIndex).getSize()){
                    //if the partition is not in use 
                         if(!mainMemory.at(lastIndex).Used()){
                              //set the job to that partition
                              mainMemory.at(lastIndex).setJob(jobList.at(i).getJobId());
                              //set the partition to that job
                              jobList.at(i).setPartition(mainMemory.at(lastIndex).getPartitionId());
                              //set the waste of the partition 
                              mainMemory.at(lastIndex).setWaste(mainMemory.at(lastIndex).getSize() - jobList.at(i).getSize());
                              jobList.at(i).setWaste(mainMemory.at(lastIndex).getSize() - jobList.at(i).getSize());
                              break;//break out of the inner for loop and continue on with the next job
                         }
               }
          }
     }
     outputInfo(mainMemory,jobList);
}
     
void bestFit(vector<Partition>& mainMemory, vector<Job>& jobList){
     int bestIndex = -1;
     int  bestWaste;
     int waste;

     for(int i = 0; i<jobList.size(); i++){

          for(int j = 0; j<mainMemory.size();j++){
               //if its the beggining of the partition set the best waste to the first waste.
               if(j==0){
                    bestWaste = mainMemory.at(j).getSize() - jobList.at(i).getSize();
                    waste = mainMemory.at(j).getSize() - jobList.at(i).getSize();
                    if((waste>=0 && waste<=bestWaste && !mainMemory.at(j).Used()) || (bestWaste<0 && waste>=0 && !mainMemory.at(j).Used())  ){
                         bestWaste = waste;
                         bestIndex = j;
                    }
               }
               else{
                    waste = mainMemory.at(j).getSize() - jobList.at(i).getSize();
                    //if the initial waste best waste is negative and the new wate is positive then 
                    //make that the new best waste because a negative waste means it will not fit
                    //or if the waste is positive and it is better than the current best waste 
                    if((waste>=0 && waste<=bestWaste && !mainMemory.at(j).Used()) || (bestWaste<0 && waste>=0 && !mainMemory.at(j).Used())  ){
                         bestWaste = waste;
                         bestIndex = j;
                    }
               }
                 
          }

          //if there is a partition that best fits the job and it is not in use then assign the job to the partition.
          if(bestIndex>=0){
               //set the job to that partition
               mainMemory.at(bestIndex).setJob(jobList.at(i).getJobId());
               //set the partition to that job
               jobList.at(i).setPartition(mainMemory.at(bestIndex).getPartitionId());
               //set the waste of the partition 
               mainMemory.at(bestIndex).setWaste(mainMemory.at(bestIndex).getSize() - jobList.at(i).getSize());
               jobList.at(i).setWaste(mainMemory.at(bestIndex).getSize() - jobList.at(i).getSize());
          }
          bestIndex =-1;
     }
     outputInfo(mainMemory, jobList);
}
