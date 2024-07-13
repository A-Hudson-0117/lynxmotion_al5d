#include <lynxmotion_al5d_description/manager.h>

Manager::Manager(ros::NodeHandle& nh_)
{
    nh = nh_;
    pub_joints = nh.advertise<std_msgs::Float64MultiArray>("/lynxmotion_al5d/joints_positions/command", 1000);
}

bool Manager::reset(std_srvs::Empty::Request &req,
            std_srvs::Empty::Response &res)
{
    std_srvs::Empty::Request b_req;
    std_srvs::Empty::Response b_res;

    std_msgs::Float64MultiArray msg;
    std::vector<double> vals = {0.00, 1.5700, -1.5700, 0.00, 0.00, 0.00};
    msg.data.clear();
    msg.data.insert(msg.data.end(), vals.begin(), vals.end());

    // Now send the robot back to the (0 0 0 0 0 0) position
    while (pub_joints.getNumSubscribers() < 1)
    {
        // Wait until there is connection.
    }

    pub_joints.publish(msg);

    return true;
}
