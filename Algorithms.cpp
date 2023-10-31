#include "Algorithms.h"
#include "Job.h"
#include "Partition.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

     void outputInfo(vector<Partition>& mainMemory, vector<Job>& jobList){
          cout<<"size of jobList: "<<jobList.size()<<endl;
          jobList.at(3).getJobId();
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
     
