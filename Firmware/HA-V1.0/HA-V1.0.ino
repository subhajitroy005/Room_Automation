#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define OK_BTN 2
#define UP_BTN 3
#define DOWN_BTN 4

struct lcd_messages
{
  char init_msg[14] = "Initializing..";
  char can_ok[6] = "CAN OK";
  char can_status = 'C';
};
  
  

struct _lcd_gui
{
  lcd_messages lcd_msg; 
  unsigned char ok_btn = 0;
  unsigned char up_btn = 0;
  unsigned char down_btn = 0;
  unsigned char home_screen_status = 0;
}gui;



int ok_buttonState;             // the current reading from the input pin
int last_ok_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_ok_DebounceTime = 0;  // the last time the output pin was toggled
int up_buttonState;             // the current reading from the input pin
int last_up_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_up_DebounceTime = 0;  // the last time the output pin was toggled
int down_buttonState;             // the current reading from the input pin
int last_down_ButtonState = LOW;   // the previous reading from the input pin
unsigned long last_down_DebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


unsigned char motor_run_status =1;
unsigned char can_status =1;


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcd_home(void);


void setup()
{
  // Initialize the IOS
  pinMode(OK_BTN,INPUT);
  pinMode(UP_BTN,INPUT);
  pinMode(DOWN_BTN,INPUT);




  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(15,0);
  lcd.print(gui.lcd_msg.can_status);
  delay(2000);

  
}
