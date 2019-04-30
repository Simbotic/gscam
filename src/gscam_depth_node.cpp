
#include <ros/ros.h>
#include <gscam_depth/gscam_depth.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "gscam_depth_publisher");
  ros::NodeHandle nh, nh_private("~");

  gscam_depth::GSCam gscam_driver(nh, nh_private);
  gscam_driver.run();

  return 0;
}

