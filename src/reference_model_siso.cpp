#include "reference_model_siso.hpp"

ReferenceFilterSiso::ReferenceFilterSiso()
    : state_ddot(0), state_dot(0), state(0), temp(0) {}

void ReferenceFilterSiso::model_order_2(
    double desired_state,
    double omega_n,
    double zeta,
    double sat_state_ddot_lower,
    double sat_state_ddot_upper,
    double sat_state_dot_lower,
    double sat_state_dot_upper,
    double dt) {

  // compute state_ddot
  state_ddot = desired_state * omega_n * omega_n;

  // saturation limit ddot
  if (state_ddot < sat_state_ddot_lower) {
    state_ddot = sat_state_ddot_lower;
  } else if (state_ddot > sat_state_ddot_upper) {
    state_ddot = sat_state_ddot_upper;
  } else {
    state_ddot = state_ddot;
  }

  // compute state_dot
  state_dot = state_dot + (state_ddot + (-2 * zeta * omega_n * state_dot) +
                           (-omega_n * omega_n * state)) *
                              dt;

  // saturation limit state_dot
  if (state_dot < sat_state_dot_lower) {
    state_dot = sat_state_dot_lower;
  } else if (state_dot > sat_state_dot_upper) {
    state_dot = sat_state_dot_upper;
  } else {
    state_dot = state_dot;
  }

  // compute state
  state = state + state_dot * dt;
}

void ReferenceFilterSiso::model_order_3(
    double desired_state,
    double omega_n,
    double zeta,
    double sat_state_ddot_lower,
    double sat_state_ddot_upper,
    double sat_state_dot_lower,
    double sat_state_dot_upper,
    double dt) {
  // compute low-pass filtered acceleration input
  double temp = (desired_state - temp) * omega_n * dt;
  //low-pass filtered acceleration input to 2nd order system.
  model_order_2(
      temp, omega_n, zeta, sat_state_ddot_lower, sat_state_ddot_upper,
      sat_state_dot_lower, sat_state_dot_upper, dt);
}

double ReferenceFilterSiso::get_state_ddot() {
  return state_ddot;
}

double ReferenceFilterSiso::get_state_dot() {
  return state_dot;
}

double ReferenceFilterSiso::get_state() {
  return state;
}
