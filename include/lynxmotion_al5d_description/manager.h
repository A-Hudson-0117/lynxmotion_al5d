#include <cstring>
#include <vector>
#include <thread>
#include <ros/ros.h>
#include "std_srvs/Empty.h"
#include "gazebo_msgs/SpawnModel.h"
#include "gazebo_msgs/DeleteModel.h"
#include "std_msgs/Float64MultiArray.h"

#define ROBOT_NAMESPACE "/lynxmotion_al5d"
#define ROBOT_PARAM_SUFFIX "_lego_description"

class Manager
{
public:
    Manager(ros::NodeHandle& n);
    static int numSpawned;
    bool clear(std_srvs::Empty::Request &req,
                std_srvs::Empty::Response &res);
    bool reset(std_srvs::Empty::Request &req,
                std_srvs::Empty::Response &res);
private:
    ros::Publisher pub_joints;
    ros::NodeHandle nh;
};

