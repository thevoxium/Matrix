#include "src/body.hpp"
#include "src/math/vector.hpp"
#include "src/update.hpp"
#include <iostream>
#include <iomanip>

int main() {
  Body b;
  
  // Set position using Vector
  Vector::Vector position(0.0f, 100.0f, 0.0f);
  b.set_property("position", position);
  
  // Set velocity and acceleration as Vectors for 3D kinematics
  Vector::Vector velocity(0.0f, 10.0f, 0.0f);  // Initial downward velocity
  Vector::Vector acceleration(0.0f, -9.8f, 0.0f);  // Gravity (downward)
  b.set_property("velocity", velocity);
  b.set_property("acceleration", acceleration);
  
  // Target 60 fps: dt = 1/60 seconds
  const float dt = 1.0f / 60.0f;
  
  // Print initial state
  std::cout << std::fixed << std::setprecision(4);
  Vector::Vector current_position = b.get<Vector::Vector>("position");
  Vector::Vector current_velocity = b.get<Vector::Vector>("velocity");
  std::cout << "Initial Position: (" << current_position.i << ", " 
            << current_position.j << ", " << current_position.k << ")" << std::endl;
  std::cout << "Initial Velocity: (" << current_velocity.i << ", " 
            << current_velocity.j << ", " << current_velocity.k << ")" << std::endl;
  std::cout << std::endl;
  
  // Keep updating until position j reaches 0
  int frame_count = 0;
  while (current_position.j > 0.0f) {
    // Perform kinematics update
    Update::kinematics_update(b, dt);
    
    // Get updated position and velocity
    current_position = b.get<Vector::Vector>("position");
    current_velocity = b.get<Vector::Vector>("velocity");
    
    frame_count++;
    
    // Print results (every frame or periodically)
    if (frame_count % 60 == 0 || current_position.j <= 0.0f) {
      std::cout << "Frame " << frame_count << " - Position: (" << current_position.i << ", " 
                << current_position.j << ", " << current_position.k << ")" << std::endl;
      std::cout << "         Velocity: (" << current_velocity.i << ", " 
                << current_velocity.j << ", " << current_velocity.k << ")" << std::endl;
    }
  }
  
  // Print final state
  std::cout << std::endl;
  std::cout << "Final Position: (" << current_position.i << ", " 
            << current_position.j << ", " << current_position.k << ")" << std::endl;
  std::cout << "Final Velocity: (" << current_velocity.i << ", " 
            << current_velocity.j << ", " << current_velocity.k << ")" << std::endl;
  std::cout << "Total frames: " << frame_count << std::endl;
  
  return 0;
}
