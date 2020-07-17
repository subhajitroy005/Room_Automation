#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>

#define OK_BTN    5    // OK Button
#define UP_BTN    3    // UP Button
#define DOWN_BTN  2    // Down Button
#define SET_BTN   4    // SET Button
#define START_BTN 6    // Start and stop btn
#define RELAY 10
#define SCAN 11

#define ON HIGH
#define OFF LOW

struct _lcd_gui // Structure for controlling data on the gui
{
  unsigned char ok_btn = 0;
  unsigned char up_btn = 0;
  int up_btn_count = 0;
  unsigned char down_btn = 0;
  int down_btn_count =0;
  unsigned char set_btn = 0;
  unsigned char setup_status = 0;
}gui;

struct _motor
{
  unsigned char motor_run_status;
  unsigned char timer_value;
  unsigned char timer_counter;
  unsigned char relay_safe_status;
  unsigned char motor_start_index = 0;
  unsigned char start_btn_state = 0;
  unsigned char motor_start_pressed =0;
}motor;
 

int ok_buttonState;             // the current reading from the input pin
int last_ok_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_ok_DebounceTime = 0;  // the last time the output pin was toggled
int up_buttonState;             // the current reading from the input pin
int last_up_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_up_DebounceTime = 0;  // the last time the output pin was toggled
int down_buttonState;             // the current reading from the input pin
int last_down_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_down_DebounceTime = 0;  // the last time the output pin was toggled
int set_buttonState;             // the current reading from the input pin
int last_set_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_set_DebounceTime = 0;  // the last time the output pin was toggled
int start_buttonState;             // the current reading from the input pin
int last_start_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_start_DebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

unsigned long timer_1,time_index;
unsigned char motor_timer_start;
unsigned char run_forever = 1;
unsigned long millis_count;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcd_home(void);
void lcd_timer_setup(int up_btn_status);

void setup()
{
  // Variable initialization
   gui.ok_btn = 0;
   gui.up_btn = 0;
   gui.down_btn =0;
   gui.set_btn =0;
   gui.setup_status =0;

  pinMode(OK_BTN,INPUT);
  pinMode(UP_BTN,INPUT);
  pinMode(DOWN_BTN,INPUT);
  pinMode(SET_BTN,INPUT);
  pinMode(RELAY,OUTPUT);
  pinMode(SCAN,INPUT);
  
  lcd.init(); // Initialize the LCD            
  lcd.backlight(); // On the Back Light
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Hi");
  lcd.setCursor(2,1);
  lcd.print("Prabhat Roy");
  delay(2500);
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Hi");
  lcd.setCursor(2,1);
  lcd.print("Dipali Roy");
  delay(2500);
  // Initializing The Platform
  motor.start_btn_state = 0;
  motor.motor_run_status = 0;
  motor.motor_start_pressed = 0;
  motor.timer_value = EEPROM.read(0);
  motor_timer_start = 0;

  //Check Rleay
  if(digitalRead(SCAN))
    motor.relay_safe_status = 1;
  else
    motor.relay_safe_status = 0;
   
  lcd_home();
}
