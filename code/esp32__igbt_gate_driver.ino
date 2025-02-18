#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_ADDRESS 0x3C

#define PWM_CHANNEL 0
#define PWM_RESOLUTION 8  // 8-bit resolution (0-255)
#define PWM_PIN 16        // Change to your desired PWM output pin
#define PWM_MIN_FREQ 10000
#define PWM_MAX_FREQ 100000
#define PWM_STEP 200  // Frequency step per encoder increment
#define START_FREQ 50000

#define ENCODER_CLK 18
#define ENCODER_DT 19
#define ENCODER_SW 5

volatile int frequency = START_FREQ;
const int stepSize = 100;
const int dutyCycle = 122;
///
const int baseStep = 100;              // Minimum step size
const int fastRotationThreshold = 50;  // Time in ms for fast rotation
const int maxStep = 2000;              // Maximum step size for fast rotation
volatile bool buttonPressed = false;
volatile unsigned long lastEncoderTime = 0;
volatile int lastClkState;
volatile bool encoderMoved = false;

// OLED Display
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

void IRAM_ATTR resetFrequency() {
  buttonPressed = true;
}

void IRAM_ATTR encoderISR() {
  int stateCLK = digitalRead(ENCODER_CLK);
  if (stateCLK != lastClkState) {
    if (digitalRead(ENCODER_DT) != stateCLK) {
      frequency += stepSize;
    } else {
      frequency -= stepSize;
    }
    frequency = constrain(frequency, PWM_MIN_FREQ, PWM_MAX_FREQ);
    ledcChangeFrequency(PWM_PIN, frequency, PWM_RESOLUTION);
    ledcWrite(PWM_PIN, dutyCycle);
    encoderMoved = true;
  }
  lastClkState = stateCLK;
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.print("f:");
  display.print(frequency / 1000.0, 1);  // Convert to kHz with 1 decimal place for better display
  display.print("kHz");
  display.display();
}

void welcomeDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Welcome To");
  display.setCursor(0, 20);
  display.print("Induction");
  display.setCursor(0, 40);
  display.print("Heating");
  display.display();
}

void setup() {
  Serial.begin(115200);

  // setup Rotary Encoder Pins
  pinMode(ENCODER_CLK, INPUT_PULLUP);
  pinMode(ENCODER_DT, INPUT_PULLUP);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  // Attach Interrupts
  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), encoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_SW), resetFrequency, FALLING);

  // setup LEDC PWM
  lastClkState = digitalRead(ENCODER_CLK);
  ledcAttach(PWM_PIN, frequency, PWM_RESOLUTION);
  ledcWrite(PWM_PIN, dutyCycle);
  ledcChangeFrequency(PWM_PIN, frequency, PWM_RESOLUTION);
  ledcWrite(PWM_PIN, dutyCycle);


  // setup OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED initialization failed!");
    while (true)
      ;
  }
  // Show an intro display message
  welcomeDisplay();

  delay(5000);
  updateDisplay();
  ledcChangeFrequency(PWM_PIN, frequency, PWM_RESOLUTION);
  ledcWrite(PWM_PIN, dutyCycle);
  delay(100);
}

void loop() {
  if (encoderMoved) {
    updateDisplay();
    encoderMoved = false;
  }

  if (buttonPressed) {
    buttonPressed = false;
    frequency = START_FREQ;
    ledcChangeFrequency(PWM_PIN, frequency, PWM_RESOLUTION);
    ledcWrite(PWM_PIN, dutyCycle);
    updateDisplay();
    // Pressing the rotary encoder button quick resets to desired startup frequency
    Serial.println("Frequency reset to 50.0 kHz");
  }
  delay(10);
}
