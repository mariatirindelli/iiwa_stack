#pragma once

#include <functional>
#include "iiwa_ros/iiwa_ros.hpp"
#include "iiwa_ros/service/time_to_destination.hpp"

namespace iiwa_ros {
namespace command {
class GenericCommand : public Robot {
public:
  GenericCommand() = default;
  //  GenericCommand(const std::string& robot_namespace) : Robot{robot_namespace}, time_to_destination_{robot_namespace}
  //  {}
  //  void init(const std::string& robot_namespace) override;

protected:
  std::function<void()> callback_{};
  iiwa_ros::service::TimeToDestinationService time_to_destination_{};

  void completedMotionWatcher();
};
}  // namespace command
}  // namespace iiwa_ros
