void loop()
{
  unsigned char ok_reading = digitalRead(OK_BTN);
  unsigned char up_reading = digitalRead(UP_BTN);
  unsigned char down_reading = digitalRead(DOWN_BTN);
 // Ok Button deboounce======================== 
  if (ok_reading != last_ok_ButtonState)
    {
      last_ok_DebounceTime = millis();
    }
  if ((millis() - last_ok_DebounceTime) > debounceDelay) 
    {
      if (ok_reading != ok_buttonState) 
        {
          ok_buttonState = ok_reading;
          if (ok_buttonState == HIGH) 
              {
               gui.ok_btn = 1;
              }
        }
     }
 last_ok_ButtonState = ok_reading;
 // UP Button deboounce======================== 
  if (up_reading != last_up_ButtonState)
    {
      last_up_DebounceTime = millis();
    }
  if ((millis() - last_up_DebounceTime) > debounceDelay) 
    {
      if (up_reading != up_buttonState) 
        {
          up_buttonState = up_reading;
          if (up_buttonState == HIGH) 
              {
               gui.up_btn = 1;
              }
        }
     }
 last_up_ButtonState = up_reading;
 // DOWN Button deboounce======================== 
if (down_reading != last_down_ButtonState)
    {
      last_down_DebounceTime = millis();
    }
  if ((millis() - last_down_DebounceTime) > debounceDelay) 
    {
      if (down_reading != down_buttonState) 
        {
          down_buttonState = down_reading;
          if (down_buttonState == HIGH) 
              {
               gui.down_btn = 1;
              }
        }
     }
 last_down_ButtonState = down_reading;
//======================================================================

// Home Screen 

if(gui.home_screen_status | gui.ok_btn)
  {
    gui.home_screen_status = 0;
   gui.ok_btn =0;
    lcd_home();
  }
    
}
