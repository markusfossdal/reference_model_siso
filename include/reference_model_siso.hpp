#pragma once

class ReferenceFilterSiso {
 public:
  ReferenceFilterSiso();
  void model_order_2(
      double desired_state,
      double omega_n,
      double zeta,
      double sat_state_ddot_lower,
      double sat_state_ddot_upper,
      double sat_state_dot_lower,
      double sat_state_dot_upper,
      double dt);
  void model_order_3(
      double desired_state,
      double omega_n,
      double zeta,
      double sat_state_ddot_lower,
      double sat_state_ddot_upper,
      double sat_state_dot_lower,
      double sat_state_dot_upper,
      double dt);
  double get_state_ddot();
  double get_state_dot();
  double get_state();

 private:
  double state_ddot, state_dot, state;
  double dt;
};