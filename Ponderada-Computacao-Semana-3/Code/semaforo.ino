#define YELLOW 3
#define GREEN  5
#define RED    6

class Led {
public:
  explicit Led(uint8_t pin) : pin_(pin) {}
  
  void begin() { 
    pinMode(pin_, OUTPUT); 
  }
  
  void on() { 
    digitalWrite(pin_, HIGH); 
  }
  
  void off() { 
    digitalWrite(pin_, LOW); 
  }
  
  void hold(unsigned long ms) { 
    on(); 
    delay(ms); 
    off(); 
  }

private:
  uint8_t pin_;
};

Led ledRed(RED);
Led ledGreen(GREEN);
Led ledYellow(YELLOW);

void setup() {
  ledRed.begin();
  ledGreen.begin();
  ledYellow.begin();
}

void loop() {
  ledGreen.hold(4000);
  ledYellow.hold(2000);
  ledRed.hold(6000);
}
