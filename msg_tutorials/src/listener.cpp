//
// Created by kevinlinpr on 19-3-21.
//

#include "ros/ros.h"
#include "info_msgs/personInfo.h"
#include <iostream>
using namespace std;
void chatterCallback(const info_msgs::personInfo::ConstPtr& msg){
    cout<<"I heard:"<<msg->firstName.c_str()<<"|"<<msg->lastName.c_str()<<"|"<<msg->age<<"|"<<msg->score<<endl;
}
int main(int argc,char** argv){
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);
    ros::spin();
    return 0;
}