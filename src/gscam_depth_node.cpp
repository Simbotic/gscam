
#include <ros/ros.h>
#include <gscam_depth/gscam_depth.h>
#include <arrayfire.h>

int main(int argc, char** argv) {
  // Select a device and display arrayfire info
  int device = argc > 1 ? atoi(argv[1]) : 0;
  af::setDevice(device);
  af::info();

  ros::init(argc, argv, "gscam_depth_publisher");
  ros::NodeHandle nh, nh_private("~");

  gscam_depth::GSCam gscam_driver(nh, nh_private);
  gscam_driver.run();

  return 0;
}

