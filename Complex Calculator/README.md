## Complex Calculator <br>
this app can multiple operations according to its precedence <br>
we used TIVA C (TM4C123GH6PM) to interfacw with Keypad and LCD <br>
Connections: <br>
LCD: can be changed from LCD.h <br>
we used PORTB to connect to LCD <br>
DATA4 PIN4 - DATA5 PIN5 - DATA6 PIN6 - DATA7 PIN7 <br>
RS_PIN PIN0 - RW_PIN PIN1 - EN_PIN PIN2 <br>
<br>
<br>
Keypad: can be changed from keypad.h <br>
Rows are connected to PORTE <br>
R1:PIN0 - R2:PIN1 - R3:PIN2 - R4:PIN3 <br>
Columns are connected to PORTC <br>
C1:PIN4 - C2:PIN5 - C3:PIN6 - C4:PIN7 <br>

Test cases to test app <br>
= --> wrong syntax <br>
1= --> 1 <br>
-= --> syntax error <br>
3+= --> syntax error <br>
3+3= --> 6 <br>
3+3*3= --> 12 <br>
3-3*3= --> -6 <br>
3-3**3= --> syntax error <br>
3-5*6+9= --> -18 <br>
3-5/0+3= --> Divide by zero <br>