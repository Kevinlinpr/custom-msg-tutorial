//
// Created by kevinlinpr on 19-3-21.
//
#include "ros/ros.h"
#include "info_msgs/personInfo.h"
int main(int argc, char** argv){
    ros::init(argc,argv,"talker");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<info_msgs::personInfo>("chatter",1000);
    ros::Rate loop_rate(10);
    int count = 0;
    uint8_t age = 10;
    uint32_t score = 100;
    while(ros::ok()){
        info_msgs::personInfo msg;
        msg.age = age;
        msg.firstName = "Chen";
        msg.lastName = "Yong lin";
        msg.score = score;
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
        ++age;
        ++score;
    }
    return 0;
}