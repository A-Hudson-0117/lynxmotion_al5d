#include <ros/ros.h>
#include <lynxmotion_al5d_description/manager.h>

int main (int argc, char **argv)
{
    ros::init(argc, argv, "spawn_brick_server");
    ros::NodeHandle nh;
    Manager nodeManager(nh);

    char resetServiceName [64] = "/lynxmotion_al5d/reset";

    ros::ServiceServer resetService = nh.advertiseService(resetServiceName, &Manager::reset, &nodeManager);

    ROS_INFO("Bricks management service loaded!");
    ros::spin();
    
    return 0;
}
