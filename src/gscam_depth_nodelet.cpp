
#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <gscam_depth/gscam_depth_nodelet.h>

PLUGINLIB_EXPORT_CLASS(gscam_depth::GSCamNodelet, nodelet::Nodelet) 

namespace gscam_depth {
  GSCamNodelet::GSCamNodelet() :
    nodelet::Nodelet(),
    gscam_driver_(NULL),
    stream_thread_(NULL)
  {
  }

  GSCamNodelet::~GSCamNodelet() 
  {
    stream_thread_->join();
  }

  void GSCamNodelet::onInit()
  {
    gscam_driver_.reset(new gscam_depth::GSCam(this->getNodeHandle(), this->getPrivateNodeHandle()));
    stream_thread_.reset(new boost::thread(boost::bind(&GSCam::run, gscam_driver_.get())));
  }
}
