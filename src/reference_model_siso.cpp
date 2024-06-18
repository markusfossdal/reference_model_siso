#include "reference_model_siso.hpp"

ReferenceFilterSiso::ReferenceFilterSiso() : eta_ddot(0), eta_dot(0), eta(0) {}

void ReferenceFilterSiso::model_order_2(
    double desired_signal,
    double omega_n,
    double zeta,
    double sat_eta_ddot,
    double sat_eta_dot,
    double dt) {

  // compute eta_ddot
  eta_ddot = desired_signal * omega_n * omega_n;

  // saturation limit ddot
  if (eta_ddot > sat_eta_ddot) {
    eta_ddot = sat_eta_ddot;
  }

  // compute eta_dot
  eta_dot = eta_dot + (eta_ddot + (-2 * zeta * omega_n * eta_dot) +
                       (-omega_n * omega_n * eta)) *
                          dt;

  // saturation limit eta_dot
  if (eta_dot > sat_eta_dot) {
    eta_dot = sat_eta_dot;
  }

  // compute eta
  eta = eta + eta_dot * dt;
}

void ReferenceFilterSiso::model_order_3(
    double desired_signal,
    double omega_n,
    double zeta,
    double sat_eta_ddot,
    double sat_eta_dot,
    double dt) {
  // compute low-pass filtered acceleration input
  double temp = (desired_signal - temp) * omega_n * dt;
  //low-pass filtered acceleration input to 2nd order system.
  model_order_2(temp, omega_n, zeta, sat_eta_ddot, sat_eta_dot, dt);
}

double ReferenceFilterSiso::get_eta_ddot() {
  return eta_ddot;
}

double ReferenceFilterSiso::get_eta_dot() {
  return eta_dot;
}

double ReferenceFilterSiso::get_eta() {
  return eta;
}
