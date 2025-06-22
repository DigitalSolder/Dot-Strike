# Dot-Strike
🎯Dot Strike:An interactive arcade-style game built using Arduino UNO, where players control a dot on an 8x8 LED matrix using a joystick to hit randomly placed targets. The game includes a countdown timer, buzzer feedback, and real-time OLED display of score and time.
🕹️ Features
🎮 Move the player using a 2-axis analog joystick

🎯 Hit targets by aligning and pressing the joystick button

⏱ 60-second countdown timer for game duration

🧠 OLED display shows live score and remaining time

🔊 Buzzer sounds on hit, miss, and game over

💡 8x8 LED Matrix displays player and target positions

🚫 Game freezes on time up (can be extended later)

🧩 Components Used
Component	Description
Arduino UNO	Microcontroller board
MAX7219 LED Matrix	Displays the player & target
Analog Joystick Module	Controls player movement and shooting
SSD1306 OLED Display	Displays score and timer
Piezo Buzzer	Provides audio feedback
Wires, Breadboard	For connections

🔌 Pin Connections
MAX7219 ↔ Arduino UNO
Pin	Arduino Pin
VCC	5V
GND	GND
DIN	D11
CLK	D13
CS (LOAD)	D10

Joystick ↔ Arduino UNO
Terminal	Arduino Pin
HORZ	A0
VERT	A1
SEL	D2

OLED ↔ Arduino UNO
Terminal	Arduino Pin
SDA	A4
SCL	A5

Buzzer ↔ Arduino UNO
Terminal	Arduino Pin
+	D3
–	GND

🧠 Game Logic
Player starts at the center of the LED matrix.

Random target appears somewhere on the grid.

Use the joystick to move the player to the target's position.

Press the joystick button to fire.

✅ If aligned: +1 score and new target

❌ If missed: buzzer sound only

The OLED shows the current score and time left.

Game ends after 60 seconds with a “Game Over” screen.

📂 File Structure
bash
Copy
Edit
Joystick-Target-Game/
├── Joystick_Target_Game.ino   # Main Arduino sketch
├── README.md                  # Project documentation
🔧 Future Enhancements
🔁 Add restart button after Game Over

💾 Save high score in EEPROM

🔄 Add moving targets

🧩 Level system based on score

🕹️ Menu screen on OLED (difficulty selection)

🧪 Simulation
https://wokwi.com/projects/434471761012419585

