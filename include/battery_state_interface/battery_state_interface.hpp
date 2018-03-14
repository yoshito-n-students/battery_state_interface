#ifndef BATTERY_STATE_INTERFACE_BATTERY_STATE_INTERFACE
#define BATTERY_STATE_INTERFACE_BATTERY_STATE_INTERFACE

#include <string>

#include <hardware_interface/internal/hardware_resource_manager.h>
#include <sensor_msgs/BatteryState.h>

namespace battery_state_interface {

// requirement for a hardware handle
//  - copyable to be mapped in HardwareResourceManager
//  - has getName() to be used in HardwareResouceManager
//  - has reference to data
class BatteryStateHandle {
public:
  BatteryStateHandle() : name_(), data_(NULL) {}

  BatteryStateHandle(const std::string &name, const sensor_msgs::BatteryState *const data)
      : name_(name), data_(data) {}

  virtual ~BatteryStateHandle() {}

  std::string getName() const { return name_; }
  sensor_msgs::BatteryState getData() const { return *data_; }
  const sensor_msgs::BatteryState *getDataPtr() const { return data_; }

private:
  std::string name_;
  const sensor_msgs::BatteryState *data_;
};

class BatteryStateInterface
    : public hardware_interface::HardwareResourceManager< BatteryStateHandle > {};

} // namespace battery_state_interface

#endif