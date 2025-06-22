**Dot-Strike**
---

# 🎯 Dot-Strike

**An Interactive LED Target Game using Arduino UNO**

---

## 📘 Overview

**Dot-Strike** is an interactive arcade-style game built with **Arduino UNO**, where players control a moving dot on an **8x8 LED matrix** using a **joystick** to aim and hit randomly positioned targets. The game features a **60-second countdown timer**, **buzzer feedback**, and a **real-time OLED display** showing the player's score and remaining time.

---

## 🕹️ Features

* 🎮 **Joystick-Controlled Movement**
  Navigate the dot on the LED matrix using a 2-axis analog joystick.

* 🎯 **Target Hit Mechanism**
  Align the player dot with the target and press the joystick button to shoot.

* ⏱ **Countdown Timer**
  60 seconds of game time displayed on OLED.

* 📟 **Live OLED Display**
  Shows current score and remaining time in real-time.

* 🔊 **Buzzer Feedback**
  Plays sounds on hit, miss, and game over events.

* 💡 **8x8 LED Matrix Gameplay**
  LED matrix visually shows the player and the target positions.

* 🚫 **Auto Game End**
  Freezes the game and displays “Game Over” once the timer expires.

---

## 🧩 Components Used

| Component              | Description                        |
| ---------------------- | ---------------------------------- |
| **Arduino UNO**        | Microcontroller board              |
| **MAX7219 LED Matrix** | Visual grid for game interaction   |
| **Analog Joystick**    | Controls player movement & fire    |
| **SSD1306 OLED**       | Displays score and countdown timer |
| **Piezo Buzzer**       | Provides audio feedback            |
| **Breadboard + Wires** | Connections for components         |

---

## 🔌 Pin Connections

### MAX7219 → Arduino UNO

| MAX7219 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| DIN         | D11         |
| CLK         | D13         |
| CS (LOAD)   | D10         |

---

### Joystick → Arduino UNO

| Joystick Terminal | Arduino Pin |
| ----------------- | ----------- |
| HORZ              | A0          |
| VERT              | A1          |
| SEL (Button)      | D2          |

---

### OLED Display → Arduino UNO

| OLED Pin | Arduino Pin |
| -------- | ----------- |
| SDA      | A4          |
| SCL      | A5          |

---

### Buzzer → Arduino UNO

| Buzzer Pin | Arduino Pin |
| ---------- | ----------- |
| +          | D3          |
| –          | GND         |

---

## 🧠 Game Logic

* The player dot starts at the center of the LED matrix.
* A random target is generated on the grid.
* The player uses the joystick to move and aim.
* Pressing the joystick button "fires":

  * ✅ If aligned: +1 to score, new target appears
  * ❌ If missed: buzzer sound only
* The OLED screen displays the **current score** and **remaining time**.
* The game automatically ends after **60 seconds** with a “Game Over” message.

---

---

## 🔧 Future Enhancements

* 🔁 Add a **restart button** after Game Over
* 💾 Store **high score** using EEPROM
* 🔄 Implement **moving targets** for added difficulty
* 🧩 Add **leveling system** based on score
* 🕹️ Include an OLED **menu screen** for difficulty selection

---

## 🧪 Simulation (Wokwi)

You can try the project instantly on the Wokwi simulator:
👉 https://wokwi.com/projects/434471761012419585


