#ifndef _MARKER_UTILS_H_
#define _MARKER_UTILS_H_


#include <ros/ros.h>

#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>

#include <interactive_markers/interactive_marker_server.h>

#include <interactive_markers/menu_handler.h>
#include <jsk_interactive_marker/SetPose.h>
#include <jsk_interactive_marker/MarkerSetPose.h>

#include <math.h>
#include <jsk_interactive_marker/MarkerMenu.h>
#include <jsk_interactive_marker/MarkerPose.h>

#include <std_msgs/Int8.h>
#include "urdf_parser/urdf_parser.h"
#include <fstream>

#include <kdl/frames_io.hpp>
#include <tf_conversions/tf_kdl.h>


using namespace urdf;

namespace im_utils{
  geometry_msgs::Transform Pose2Transform( const geometry_msgs::Pose pose_msg);
  geometry_msgs::Pose Transform2Pose( const geometry_msgs::Transform tf_msg);
  geometry_msgs::Pose UrdfPose2Pose( const urdf::Pose pose);

  visualization_msgs::InteractiveMarkerControl makeCylinderMarkerControl(const geometry_msgs::PoseStamped &stamped, double length,  double radius, const std_msgs::ColorRGBA &color, bool use_color);
  visualization_msgs::InteractiveMarkerControl makeBoxMarkerControl(const geometry_msgs::PoseStamped &stamped, Vector3 dim, const std_msgs::ColorRGBA &color, bool use_color);
  visualization_msgs::InteractiveMarkerControl makeSphereMarkerControl(const geometry_msgs::PoseStamped &stamped, double rad, const std_msgs::ColorRGBA &color, bool use_color);
  visualization_msgs::InteractiveMarkerControl makeMeshMarkerControl(const std::string &mesh_resource, const geometry_msgs::PoseStamped &stamped, geometry_msgs::Vector3 scale, const std_msgs::ColorRGBA &color, bool use_color);
  visualization_msgs::InteractiveMarkerControl makeMeshMarkerControl(const std::string &mesh_resource, const geometry_msgs::PoseStamped &stamped, geometry_msgs::Vector3 scale);
  visualization_msgs::InteractiveMarkerControl makeMeshMarkerControl(const std::string &mesh_resource,
                                                                     const geometry_msgs::PoseStamped &stamped, geometry_msgs::Vector3 scale, const std_msgs::ColorRGBA &color);
  void addMeshLinksControl(visualization_msgs::InteractiveMarker &im, boost::shared_ptr<const Link> link, KDL::Frame previous_frame, bool use_color, std_msgs::ColorRGBA color);

  boost::shared_ptr<ModelInterface> getModelInterface(std::string model_file);
  visualization_msgs::InteractiveMarker makeLinksMarker(boost::shared_ptr<const Link> link, bool use_color, std_msgs::ColorRGBA color);

}


visualization_msgs::InteractiveMarker makeFingerControlMarker(const char *name, geometry_msgs::PoseStamped ps);
visualization_msgs::InteractiveMarker makeSandiaHandMarker(geometry_msgs::PoseStamped ps);

visualization_msgs::Marker makeSandiaFinger0Marker(std::string frame_id);
visualization_msgs::Marker makeSandiaFinger1Marker(std::string frame_id);
visualization_msgs::Marker makeSandiaFinger2Marker(std::string frame_id);

visualization_msgs::InteractiveMarker makeSandiaHandInteractiveMarker(geometry_msgs::PoseStamped ps, std::string hand, int finger, int link);

std::string getRosPathFromModelPath(std::string path);
std::string getRosPathFromFullPath(std::string path);
std::string getFullPathFromModelPath(std::string path);
std::string getFilePathFromRosPath( std::string rospath);

geometry_msgs::Pose getPose( XmlRpc::XmlRpcValue val);
double getXmlValue( XmlRpc::XmlRpcValue val );

#endif
