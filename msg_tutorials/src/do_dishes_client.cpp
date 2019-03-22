//
// Created by kevinlinpr on 19-3-23.
//
#include "ros/ros.h"
#include <actionlib/client/simple_action_client.h>
#include "dish_action/DoDishesAction.h"

//action完成后调用此函数
void doneCb(const actionlib::SimpleClientGoalState& state,
            const dish_action::DoDishesResultConstPtr& result)
{
    ROS_INFO("Finsh Wishing!");
    //任务完成就关闭节点
    ros::shutdown();
}

//action的目标任务发送给server且开始执行时，调用此函数
void activeCb()
{
    ROS_INFO("Goal is active! Begin to wish.");
}


void feedbackCb(const dish_action::DoDishesFeedbackConstPtr& feedback)
{

    ROS_INFO("Wishing dishes: %f", feedback->percent_complete);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "do_dishes_client");


    actionlib::SimpleActionClient<dish_action::DoDishesAction> client("do_dishes", true);

    ROS_INFO("Waiting for action server to start");

    client.waitForServer();
    ROS_INFO("Action server started");


    dish_action::DoDishesGoal goal;
    goal.dishwasher_id = 10;


    client.sendGoal(goal, &doneCb, &activeCb, &feedbackCb);

    ros::spin();

    return 0;
}
