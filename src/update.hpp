#pragma once
#include "body.hpp"
#include "math/vector.hpp"

namespace Update {

// Kinematics update function
// Updates position and velocity based on: v = u + at, s = s + v*dt + 0.5*a*dt²
// dt should be the delta time in seconds (for 60 fps, dt = 1/60 ≈ 0.016667)
inline void kinematics_update(Body& body, float dt) {
  // Check if body has required properties
  if (!body.has("position") || !body.has("velocity") || !body.has("acceleration")) {
    return; // Can't update without required properties
  }

  // Get current position, velocity, and acceleration
  Vector::Vector position = body.get<Vector::Vector>("position");
  Vector::Vector velocity = body.get<Vector::Vector>("velocity");
  Vector::Vector acceleration = body.get<Vector::Vector>("acceleration");

  // Update velocity: v = v + a * dt
  velocity = Vector::add(velocity, Vector::scale(acceleration, dt));

  // Update position: s = s + v*dt + 0.5*a*dt²
  // First term: v * dt
  Vector::Vector velocity_contribution = Vector::scale(velocity, dt);
  // Second term: 0.5 * a * dt²
  Vector::Vector acceleration_contribution = Vector::scale(acceleration, 0.5f * dt * dt);
  // Combine: s = s + v*dt + 0.5*a*dt²
  position = Vector::add(position, Vector::add(velocity_contribution, acceleration_contribution));

  // Store updated values back
  body.set_property("position", position);
  body.set_property("velocity", velocity);
}

} // namespace Update

