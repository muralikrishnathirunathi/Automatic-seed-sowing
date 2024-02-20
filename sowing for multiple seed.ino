#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
int pos = 0;

SoftwareSerial BTserial(10, 11); // RX | TX

void setup()
{
  Serial.begin(9600);
  BTserial.begin(9600);
  myservo.attach(9);
  myservo.write(pos);
  Serial.println("Press 1 for cotton");
  Serial.println("Press 2 for chilly");
  Serial.println("Press 3 for ground nuts ");
  Serial.println("Press 4 for green grams");
}

void loop()
{
  if (BTserial.available())
  {
    int input = BTserial.read();

    switch (input)
    {
      case '1':
         for (pos = 0; pos >= 180; pos -= 1)
        {
          myservo.write(pos);
          delay(10);
        }
        for (pos = 180; pos >= 0; pos -= 1)
       
        break;

      case '2':
        for (pos = 180; pos >= 0; pos -= 1)
        {
          myservo.write(pos);
          delay(5);
        }
        break;

      case '3':
         for (pos = 0; pos >= 180; pos -= 1)
        {
          myservo.write(pos);
          delay(10);
        }
       
        break;

      case '4':
        for (pos = 0; pos >= 180; pos -= 1)
        {
          myservo.write(pos);
          delay(10);
        }
       
        break;

      default:
        break;
    }
  }
}
