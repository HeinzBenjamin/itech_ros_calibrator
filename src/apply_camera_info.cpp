#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/SetCameraInfo.h>
#include <camera_calibration_parsers/parse.h>
#include <cstdlib>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
  ros::init(argc, argv, "apply_camera_info");
  if (argc != 3)
  {
    ROS_INFO("usage: apply_camera_info <camera topic> <calibration file>");
    return 1;
  }

  ros::NodeHandle n;

  // restructure arguments
  std::ostringstream ossSet;
  ossSet << argv[1] << "set_camera_info";
  std::string s = ossSet.str();
  std::ostringstream ossInfo;
  ros::ServiceClient client = n.serviceClient<sensor_msgs::SetCameraInfo>(s);
  sensor_msgs::SetCameraInfo srv;

  const std::string filename = argv[2];
  std::string camera_name = argv[1];
  sensor_msgs::CameraInfo camera_info;
  camera_calibration_parsers::readCalibration(filename, camera_name, camera_info);
  if (client.call(srv))
  {
    ROS_INFO("Calibration successfully applied. To double check, run 'rostopic echo <camera_info topic>' and compare the values with the values specified in you .ini file");
  }
  else
  {
    ROS_ERROR("Failed to call service camera/set_camera_info");
    return 1;
  }

  return 0;
}
