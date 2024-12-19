

// The following defines the ESP32 pins used to control the TB6612
// Motor A
#define PWMA 25
#define AIN2 17
#define AIN1 21

// Motor B
#define BIN1 22
#define BIN2 23
#define PWMB 26

// PWM frequency of pins used for PWM outputs
#define PWM_FREQ 100000

// Define PWM channel
int channel_A = 5;
int channel_B = 6;

// Define PWM accuracy, when it is 8, and PWM value is 0-255 (2^8-1)
#define ANALOG_WRITE_BITS 8
// The maximum PWM value
const uint16_t MAX_PWM = (1 << ANALOG_WRITE_BITS) - 1;
// The minimum PWM value
const uint16_t MIN_PWM = MAX_PWM / 5;

void motor_pin_init(){
  // Setting the operating mode of the ESP32 pins used to control the TB6612FNG
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Setting the channel, frequency, and resolution of the ESP32 pin used for PWM outputs 
  ledcAttach(PWMA, PWM_FREQ, ANALOG_WRITE_BITS);  // Replaces ledcSetup and ledcAttachPin
  ledcAttach(PWMB, PWM_FREQ, ANALOG_WRITE_BITS);  // Replaces ledcSetup and ledcAttachPin

  // The pin used to control rotation should be set to a low logic level to stop the motor from rotating, avoiding immediate rotation upon initialization
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

// Motor A control  
void channel_A_Ctrl(float pwmInputA) {
  // Round the pwmInput value to the nearest integer
  int pwmIntA = round(pwmInputA);
  
  if (pwmIntA == 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    return;
  }

  // Determine the direction of rotation based on the pwmInput value
  if (pwmIntA > 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    // constrain() function limits pwmIntA value between MIN_PWM and MAX_PWM
    ledcWrite(PWMA, constrain(pwmIntA, MIN_PWM, MAX_PWM));
  } else {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    ledcWrite(PWMA, constrain(-pwmIntA, MIN_PWM, MAX_PWM));
  }
}

// Motor B control  
void channel_B_Ctrl(float pwmInputB) {
  int pwmIntB = round(pwmInputB);
  
  if (pwmIntB == 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    return;
  }

  if (pwmIntB > 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    ledcWrite(PWMB, constrain(pwmIntB, MIN_PWM, MAX_PWM));
  } else {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    ledcWrite(PWMB, constrain(-pwmIntB, MIN_PWM, MAX_PWM));
  }
}



