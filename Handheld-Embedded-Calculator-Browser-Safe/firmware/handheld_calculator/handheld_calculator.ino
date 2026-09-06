#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// ---------- LCD ----------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- Keypad ----------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'/','*','-','+'},
  {'=','9','6','3'},
  {'0','8','5','2'},
  {'C','7','4','1'}
};

byte rowPins[ROWS] = {13, 12, 14, 27};
byte colPins[COLS] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------- Variables ----------
String firstNum = "";
String secondNum = "";
String equation = "";

float result = 0;
char op = 0;

bool enteringSecond = false;
bool showingResult = false;

// ---------- Setup ----------
void setup() {
  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("ESP32 Calc");
  delay(1500);
  lcd.clear();
}

// ---------- Loop ----------
void loop() {

  char key = keypad.getKey();

  if (!key) return;

  // ---------- CLEAR ----------
  if (key == 'C') {

    lcd.clear();

    firstNum = "";
    secondNum = "";
    equation = "";
    result = 0;
    op = 0;

    enteringSecond = false;
    showingResult = false;

    return;
  }

  // ---------- NUMBERS ----------
  if (key >= '0' && key <= '9') {

    // Start completely new calculation
    if (showingResult) {

      firstNum = "";
      secondNum = "";
      equation = "";
      op = 0;

      enteringSecond = false;
      showingResult = false;

      lcd.clear();
    }

    if (!enteringSecond)
      firstNum += key;
    else
      secondNum += key;

    equation += key;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(equation);

    return;
  }

  // ---------- OPERATORS ----------
  if (key == '+' || key == '-' || key == '*' || key == '/') {

    if (showingResult) {
      equation = String(result);
      firstNum = String(result);
      secondNum = "";
      showingResult = false;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(equation);
    }

    if (firstNum.length() == 0)
      return;

    op = key;
    enteringSecond = true;

    equation += key;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(equation);

    return;
  }

  // ---------- EQUALS ----------
  if (key == '=') {

    if (firstNum.length() == 0 ||
        secondNum.length() == 0 ||
        op == 0)
      return;

    float num1 = firstNum.toFloat();
    float num2 = secondNum.toFloat();

    switch (op) {

      case '+':
        result = num1 + num2;
        break;

      case '-':
        result = num1 - num2;
        break;

      case '*':
        result = num1 * num2;
        break;

      case '/':
        if (num2 == 0) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Divide by 0");

          firstNum = "";
          secondNum = "";
          equation = "";

          enteringSecond = false;
          showingResult = false;

          return;
        }
        result = num1 / num2;
        break;
    }

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print(equation);

    lcd.setCursor(0, 1);
    lcd.print("=");

    // Remove useless decimal places
    if (result == (long)result)
      lcd.print((long)result);
    else
      lcd.print(result);

    // Save result for chaining calculations
    firstNum = String(result);
    secondNum = "";
    equation = String(result);

    enteringSecond = false;
    showingResult = true;

    return;
  }
}