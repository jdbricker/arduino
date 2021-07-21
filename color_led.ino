#define red_light_pin 3
#define green_light_pin 5
#define blue_light_pin 6

#define stop_pin 8
#define resume_pin 9

int stop = 0;
int resume = 1;

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(stop_pin, INPUT_PULLUP);
  pinMode(resume_pin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  if(digitalRead(stop_pin) == LOW){
    stop = 1;
    resume = 0;
  }

  if (digitalRead(resume_pin) == LOW){
    stop = 0;
    resume = 1;
  }

  Serial.print("stop: ");
  Serial.print(stop);
  Serial.print(" resume: ");
  Serial.println(resume);

  if (stop == 1){
    RGB_color(0,0,0);
  }

  if (resume == 1){
    RGB_color(255, 0, 0); // Red
    delay(1000);
    RGB_color(0, 255, 0); // Green
    delay(1000);
    RGB_color(0, 0, 255); // Blue
    delay(1000);
  }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
