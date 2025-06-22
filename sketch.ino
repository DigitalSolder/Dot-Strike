#include <LedControl.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// MAX7219 LED Matrix
LedControl lc = LedControl(11, 13, 10, 1); // DIN, CLK, CS, # devices

// Joystick pins
const int joyX = A0;
const int joyY = A1;
const int joyBtn = 2;

// Buzzer
const int buzzer = 3;

// Player and Target Positions
int playerX = 3, playerY = 3;
int targetX, targetY;

// Game State
int score = 0;
int timer = 60;  // 🔁 Updated from 10 → 60 seconds
unsigned long lastSecond = 0;
unsigned long lastMove = 0;

// Movement deadzone threshold
const int DEADZONE = 60;

void setup() {
  Serial.begin(9600);
  
  // Joystick
  pinMode(joyBtn, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  // MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  // OLED Init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found!"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  randomSeed(analogRead(A5));
  generateTarget();
  updateDisplay();
}

void loop() {
  handleJoystickMovement();
  drawMatrix();

  if (digitalRead(joyBtn) == LOW) {
    handleFire();
    delay(200); // debounce
  }

  if (millis() - lastSecond >= 1000) {
    lastSecond = millis();
    timer--;
    updateDisplay();

    if (timer <= 0) {
      gameOver();
    }
  }
}

// Handle movement with reversed axis
void handleJoystickMovement() {
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);
  bool moved = false;

  if (millis() - lastMove > 200) {
    if (abs(xVal - 512) > DEADZONE) {
      if (xVal > 512 && playerX > 0) {
        playerX--; // Reversed
        moved = true;
      } else if (xVal < 512 && playerX < 7) {
        playerX++; // Reversed
        moved = true;
      }
    }

    if (abs(yVal - 512) > DEADZONE) {
      if (yVal > 512 && playerY < 7) {
        playerY++; // Reversed
        moved = true;
      } else if (yVal < 512 && playerY > 0) {
        playerY--; // Reversed
        moved = true;
      }
    }

    if (moved) {
      lastMove = millis();
      Serial.print("Moved to X: "); Serial.print(playerX);
      Serial.print(" Y: "); Serial.println(playerY);
    }
  }
}

void handleFire() {
  if (playerX == targetX && playerY == targetY) {
    tone(buzzer, 1000, 200);
    score++;
    generateTarget();
    Serial.println("Hit!");
  } else {
    tone(buzzer, 200, 150);
    Serial.println("Missed!");
  }
  updateDisplay();
}

void drawMatrix() {
  lc.clearDisplay(0);
  lc.setLed(0, playerY, playerX, true);  // Player
  lc.setLed(0, targetY, targetX, true);  // Target
}

void generateTarget() {
  do {
    targetX = random(8);
    targetY = random(8);
  } while (targetX == playerX && targetY == playerY);

  Serial.print("New Target at X: "); Serial.print(targetX);
  Serial.print(" Y: "); Serial.println(targetY);
}

void updateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Score: "); display.println(score);
  display.print("Time: "); display.println(timer);
  display.display();
}

void gameOver() {
  lc.clearDisplay(0);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.println("Game Over");
  display.setTextSize(1);
  display.setCursor(0, 40);
  display.print("Score: "); display.println(score);
  display.display();

  tone(buzzer, 300, 300); delay(300);
  tone(buzzer, 500, 300); delay(300);
  tone(buzzer, 800, 500); delay(500);

  while (true); // freeze
}
