#include <Morse.h>
#include <LiquidCrystal.h>

int pinBouton;
int led;
int count;
int tempsLedOff;
boolean nouvelleLettre;
boolean nouveauMot;
boolean ledOn;
int lettre;
String mot;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Morse morse;

void setup()
{
    Serial.begin(9600);
    pinBouton=10;
    led = 7;
    count = 0;
    tempsLedOff = 0;
    nouvelleLettre = false;
    nouveauMot = false;
    ledOn = false;
    lettre = 1;
    mot = "";
    pinMode(pinBouton,INPUT_PULLUP);
    pinMode(led, OUTPUT);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Ton mot:");
}
void loop()
{

  
    boolean etatBouton=digitalRead(pinBouton);

    if (nouvelleLettre) {
      if (0 == mot.length()) {
        lcd.setCursor(0, 1);
        lcd.print("                ");
        lcd.setCursor(0, 1);
      }

      char lettreTraduite = morse.getLettre(lettre);
      
      mot = mot + lettreTraduite;
      Serial.println(lettreTraduite);
      lcd.print(lettreTraduite);
      lettre = 1;
      nouvelleLettre = false;
    }

    if (nouveauMot) {
      if (0 != mot.length()) {
        // set the cursor to column 0, line 1
        // (note: line 1 is the second row, since counting begins with 0):
        lcd.setCursor(0, 1);
        // print the number of seconds since reset:
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print(mot);
        Serial.println("Mot entier : "+mot);
        mot = "";
      }
      nouveauMot = false;
    }

    if (!etatBouton) {
      digitalWrite(led,HIGH);
      count++;
    } else {
      if (0 != count) {
        digitalWrite(led,LOW);
        if (3 >= count) {
          //Serial.println("Point");
          lettre = (lettre << 1) | 0x01;
          //Serial.println(lettre, BIN);
        } else {
          //Serial.println("Trait");
          lettre = lettre << 1;
          //Serial.println(lettre, BIN);
        }
        count = 0;
        tempsLedOff = 0;
      } else {
        if (20 <= tempsLedOff && 1 == lettre) {
          nouveauMot = true;
          tempsLedOff = 0;
        } else {
          if (16 <= tempsLedOff && 1 != lettre) {
            nouvelleLettre = true;
            tempsLedOff = 0;
          } else {
            tempsLedOff++;
          }
        }
        
      }
    }
    delay(100);
}
