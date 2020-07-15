void lcd_home(void)
{
  lcd.clear();
  
  lcd.setCursor(11,0);
  lcd.print('C');
  lcd.setCursor(13,0);
  if(can_status)
    lcd.print("OK");
  else 
    lcd.print("ERR");

  
  lcd.setCursor(0,1);
  lcd.print("MOTOR : ");
  lcd.setCursor(8,1);
  if(motor_run_status)
    lcd.print("RUNNING");
  else
    lcd.print("STOP");
  
}
