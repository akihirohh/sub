#include "ros/ros.h"
#include "std_msgs/Char.h"
#include "std_msgs/Int32MultiArray.h"

char buffer[500];
int i = 0;

void danielCallback(const std_msgs::Char::ConstPtr& msg)
{
	ROS_INFO("%c", msg->data);
}

void glaucoCallback(const std_msgs::Int32MultiArray::ConstPtr& msg)
{

  char buffer2[msg->data.size()];
  for(int i =0; i<msg->data.size();i++)
  {
  	buffer2[i] = (char) (msg->data[i]/100);
  	ROS_INFO("%c", (char) (msg->data[i]/100));
  }
  
  ROS_INFO("%s",buffer2);

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/daniel", 1, danielCallback);
  //ros::Subscriber sub2 = n.subscribe("/glauco", 1, glaucoCallback);

  ros::spin();

  return 0;
}
