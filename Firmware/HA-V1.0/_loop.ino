void loop()
{
  unsigned long long temp_timer;


  unsigned char ok_reading = digitalRead(OK_BTN);
  unsigned char up_reading = digitalRead(UP_BTN);
  unsigned char down_reading = digitalRead(DOWN_BTN);
  unsigned char set_reading = digitalRead(SET_BTN);
  unsigned char start_reading = digitalRead(START_BTN);
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
        gui.up_btn_count++;
        gui.down_btn_count --;

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
        gui.down_btn_count++;
        gui.up_btn_count--;
      }
    }
  }
  last_down_ButtonState = down_reading;
  // SET Reading debounce ========================
  if (set_reading != last_set_ButtonState)
  {
    last_set_DebounceTime = millis();
  }
  if ((millis() - last_set_DebounceTime) > debounceDelay)
  {
    if (set_reading != set_buttonState)
    {
      set_buttonState = set_reading;
      if (set_buttonState == HIGH)
      {
        gui.set_btn = 1;
      }
    }
  }
  last_set_ButtonState = set_reading;
  // START BTN Reading debounce ========================
  if (start_reading != last_start_ButtonState)
  {
    last_start_DebounceTime = millis();
  }
  if ((millis() - last_start_DebounceTime) > (debounceDelay + 10))
  {
    if (start_reading != start_buttonState)
    {
      start_buttonState = start_reading;
      if (start_buttonState == HIGH)
      {
        motor.start_btn_state = ~(motor.start_btn_state);
        motor.motor_start_pressed = 1;
      }
    }
  }
  last_start_ButtonState = start_reading;
  //======================================================================

  if (gui.set_btn || gui.up_btn || gui.down_btn)
  {
    gui.set_btn = 0;
    gui.up_btn = 0;
    gui.down_btn = 0;
    lcd_timer_setup(gui.up_btn_count);
    gui.setup_status = 1;
  }

  if (gui.ok_btn)
  {
    if (gui.setup_status)
    {
      lcd_timer_setup(gui.up_btn_count);
    }
  }
  gui.ok_btn = 0;// Generally kep ok as  0

  //*****************************Motor Running LOGIC*******************************************************************************
  if(motor.motor_start_pressed)
  {
   if(motor.start_btn_state) // On the motor
    {
      motor.motor_run_status = 1;
    }
  else // off the motor
    {
      motor.motor_run_status = 0;
    } 
  }
  

  if (motor.motor_start_pressed)
  {
    motor.motor_start_pressed = 0;
    if (motor.motor_run_status) // Start the motor
    {
      if (motor.timer_value != 100) // if not for ever
      {
        timer_1 = millis();
        millis_count = millis();
        time_index = (motor.timer_value * 60000); // Put in millis
        motor_timer_start = 1;
        motor.timer_counter = 0;
        if(motor_start())
           motor.relay_safe_status = 1;
        else
            motor.relay_safe_status = 0;

        lcd_home();
      }
      else
      {
        if(motor_start())
           motor.relay_safe_status = 1;
        else
           motor.relay_safe_status = 0;
           lcd_home();
      }

    }
    else
    {
      timer_1 = 0;
      motor_timer_start = 0;
      if (motor_stop())
         motor.relay_safe_status = 1;
      else
         motor.relay_safe_status = 0;
      timer_1 = 0;
      time_index = 0;
      motor_timer_start = 0 ;
      motor.motor_run_status = 0;
      motor.timer_counter = 0;
      lcd_home();
    }
  }

  if (motor_timer_start && motor.motor_run_status)
  {
    if ((millis() - timer_1) > time_index) // Stop the motor
    {
      if (motor_stop())
        motor.relay_safe_status = 1;
      else 
        motor.relay_safe_status = 0;
      timer_1 = 0;
      time_index = 0;
      motor_timer_start = 0 ;
      motor.motor_run_status = 0;
      motor.timer_counter = 0;
      motor.start_btn_state = 0; // off the start buttion state
      lcd_home();
    }
    else // gui update
    {
      if ((millis() - millis_count) > 60000) // every 1 min
      {
        millis_count = millis();
        motor.timer_counter++;
        lcd_home();
      }
    }
  }


  //**********************************************************************************************************




}
