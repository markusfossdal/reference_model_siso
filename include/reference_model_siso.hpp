#pragma once

class ReferenceFilterSiso {
 public:
  ReferenceFilterSiso();
  void model_order_2(
      double desired_signal,
      double omega_n,
      double zeta,
      double sat_eta_ddot,
      double sat_eta_dot,
      double dt);
  void model_order_3(
      double desired_signal,
      double omega_n,
      double zeta,
      double sat_eta_ddot,
      double sat_eta_dot,
      double dt);
  double get_eta_ddot();
  double get_eta_dot();
  double get_eta();

 private:
  double eta_ddot, eta_dot, eta;
  double dt;
};