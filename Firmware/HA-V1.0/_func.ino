void lcd_home(void)
{
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print('T');
  lcd.setCursor(2,0);
    switch(motor.timer_value)
    {
      case 5:
        lcd.print("5 M");
      break;
      case 6:
       lcd.print("6 M");
      break;
      case 7:
       lcd.print("7 M");
      break;
      case 8:
       lcd.print("8 M");
      break;
      case 9:
       lcd.print("9 M");
      break;
      case 10:
       lcd.print("10 M");
      break;
      case 20:
       lcd.print("20 M");
      break;
      case 100:
       lcd.print("Nev");
      break;
      default:
      lcd.print("N/A");
      break;
    }

  if(motor.motor_run_status && motor.relay_safe_status)
  {
    lcd.setCursor(0,1);
    lcd.print("MOTOR : ");
    lcd.setCursor(8,1);
    lcd.print("RUNNING");
    if(motor.timer_value != 100)
    {
      lcd.setCursor(13,0);
      lcd.print(motor.timer_counter);      
    }
  }
  else if((motor.motor_run_status == 0) && motor.relay_safe_status)
  {
    lcd.setCursor(0,1);
    lcd.print("MOTOR : ");
    lcd.setCursor(8,1);
    lcd.print("STOP");   
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("MOTOR : ");
    lcd.setCursor(8,1);
    lcd.print("RL FAULT");
    
  }
    
}







void lcd_timer_setup(int up_btn_status)
{
   if(up_btn_status < 0)
    {
      up_btn_status = 0; // GUI constant
      gui.up_btn_count = 0;
    }
      

   if(up_btn_status > 7)
   {
    up_btn_status = 7; // GUI constant
    gui.up_btn_count = 7;
   }
      


   if(up_btn_status == 0)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("5 Min");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        
        //===========Variable manipulation==========
         EEPROM.write(0,5);
         motor.timer_value = 5;
         
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }
      
    }
    else if (up_btn_status == 1)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("6 Min"); 
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,6);
        motor.timer_value = 6;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }       
    }
    else if (up_btn_status == 2)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("7 Min");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,7);
        motor.timer_value = 7;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }        
    }
    else if (up_btn_status == 3)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("8 Min");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,8);
        motor.timer_value = 8;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }        
    }
    else if (up_btn_status == 4)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("9 Min"); 
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,9);
        motor.timer_value = 9;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }       
    }
    else if (up_btn_status == 5)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("10 Min");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,10);
        motor.timer_value = 10;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }        
    }
    else if (up_btn_status == 6)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("20 Min");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,20);
        motor.timer_value = 20;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }        
    }
    else if (up_btn_status == 7)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SET TIMER");
      lcd.setCursor(0,1);
      lcd.print("->");
      lcd.setCursor(4,1);
      lcd.print("Manual OFF");
      if(gui.ok_btn && gui.setup_status)
      {
        gui.ok_btn = 0;
        EEPROM.write(0,100);
        motor.timer_value = 100;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Success");
        gui.setup_status = 0;
        delay(1500);
        lcd_home();
      }        
    }
}


unsigned char motor_start()// On the motor
{
  digitalWrite(RELAY,ON);
  delay(1000);
  unsigned char val;
  val = digitalRead(SCAN);
  return ~(val);
}
unsigned char motor_stop() // Off the motor
{
  digitalWrite(RELAY,OFF);
  delay(1000);
  unsigned char val;
  val = digitalRead(SCAN);
  return ~(val);
}
