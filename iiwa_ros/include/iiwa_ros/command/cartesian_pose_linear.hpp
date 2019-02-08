#pragma once

#include <geometry_msgs/PoseStamped.h>
#include <iiwa_ros/command/generic_command.hpp>
#include <iiwa_ros/iiwa_ros.hpp>
namespace iiwa_ros {
namespace command {

class CartesianPoseLinear : public GenericCommand {
public:
  CartesianPoseLinear() = default;
  //  CartesianPoseLinear(const std::string& ros_namespace) : GenericCommand{ros_namespace} {}

  void setPose(const geometry_msgs::PoseStamped& pose);
  void setPose(const geometry_msgs::PoseStamped& pose, const std::function<void()> callback);
  void init(const std::string& robot_namespace) override;

private:
  iiwaCommandHolder<geometry_msgs::PoseStamped> command_{};
};

}  // namespace command
}  // namespace iiwa_ros
