/***********************
 * Servo Controller
 *
 * Purpose: Moving a servo with push buttons 
 * Authors: Lydia Calderon-Aceituno
 * January 8, 2021
 * *********************/

#include <mbed.h>

// Declare buttons, servo, and respective pins 
PwmOut servo(p21);
DigitalIn home_btn(p5);
DigitalIn increase_btn(p6);
DigitalIn decrease_btn(p7);

// Declare function

void set_servo_angle(float angle);


int main() {
  servo.period_ms(20); // Default servo period
  int previous_angle = 0;
  while (1) {
    // Checking each button state and previous angle value, and incrementing by the appropriate vlaue for each 
    if (home_btn){
      previous_angle = 0;
      set_servo_angle(previous_angle);
    }

    if(increase_btn && (previous_angle<90)){
      previous_angle = previous_angle + 1;
      set_servo_angle(previous_angle);
    }

    if(decrease_btn && (previous_angle>-90)){
      previous_angle = previous_angle - 1;
      set_servo_angle(previous_angle);
    }

    // Sleep for 100ms, then check through buttons again 
    ThisThread::sleep_for(100ms);
  }
}

// Function to move servo to specified angle (in degrees)
void set_servo_angle(float angle) {
  servo.pulsewidth_us(1500 + 10*angle);
}
