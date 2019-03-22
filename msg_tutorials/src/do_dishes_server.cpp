//
// Created by kevinlinpr on 19-3-23.
//
#include "ros/ros.h"
#include <actionlib/server/simple_action_server.h>
#include "dish_action/DoDishesAction.h"


void execute(const dish_action::DoDishesGoalConstPtr& goal,
             actionlib::SimpleActionServer<dish_action::DoDishesAction>* as)
{
    ros::Rate r(1);

    dish_action::DoDishesFeedback feedback;

    ROS_INFO("Begin to wish %d dishes.", goal->dishwasher_id);

    for(int i=0; i<goal->dishwasher_id; i++)
    {
        feedback.percent_complete = i;

        as->publishFeedback(feedback);
        r.sleep();
    }


    ROS_INFO("All dishes is wished.");

    as->setSucceeded();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "do_dishes_server");

    ros::NodeHandle n;


    actionlib::SimpleActionServer<dish_action::DoDishesAction> server(n, "do_dishes",
                                                                         boost::bind(&execute, _1, &server), false);


    server.start();

    ros::spin();

    return 0;
}
