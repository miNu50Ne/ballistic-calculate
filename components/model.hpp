#include <eigen3/Eigen/Dense>

namespace component::model {
class Model {
public:
    Model() {}

    void set_time_start(double time_start_set) { time_start_ = time_start_set; }
    void set_time_end(double time_end_set) { time_end_ = time_end_set; }
    void set_time_step(double time_step_set) { time_step_ = time_step_set; }

    double time_start() { return time_start_; }
    double time_end() { return time_end_; }
    double time_step() { return time_step_; }

    double velocity_x() { return velocity_.x(); }
    double velocity_y() { return velocity_.y(); }
    double velocity_z() { return velocity_.z(); }

    Eigen::Vector3d velocity() { return velocity_; }

private:
    double time_start_;
    double time_end_;
    double time_step_;

    Eigen::Vector3d velocity_;
};
} // namespace component::model