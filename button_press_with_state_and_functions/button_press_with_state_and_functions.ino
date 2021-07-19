const int button_a_pin = 8;
const int button_b_pin = 9;
const int led_pin =  13;   

int button_a_pressed = 0;
int button_b_pressed = 0;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_a_pin, INPUT_PULLUP);
  pinMode(button_b_pin, INPUT_PULLUP);

}

void turn_on_led(void){
  digitalWrite(led_pin, HIGH);
}

void turn_off_led(void){
  digitalWrite(led_pin, LOW);
}

void read_buttons(void){
  
  if (digitalRead(button_a_pin) == LOW) {
    button_a_pressed = 1;
    button_b_pressed = 0;
  }

  if (digitalRead(button_b_pin) == LOW) {
    button_b_pressed = 1;
    button_a_pressed = 0;
  }
}
void loop() {
  /*
   * check for button press
   * turn on/off LED accordingly
   */
  read_buttons();
  
  if (button_a_pressed) {
    turn_on_led();
  }
  
  if (button_b_pressed) {
    turn_off_led();
  }
}
