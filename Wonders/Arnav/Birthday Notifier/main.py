import datetime               
import json
import mysql.connector
from plyer import notification
import pyttsx3

#install all above used libraryusing pip install 'Library'

DB_CONFIG = {
    'host': 'localhost',
    'user': 'root',
    'password': '*******',    # Enter your own password
    'database': 'devops',     #Name of database if change you must also rename in sql database
    }
BIRTHDAYS_FILE = 'birthdays.json'
def load_birthdays():
    try:
         with open(BIRTHDAYS_FILE, 'r') as file:
            return json.load(file)
        except FileNotFoundError:
        return {}
def schedule_notifications():
    today = datetime.date.today()
     birthdays = load_birthdays()

    for birthday, name in birthdays.items():
         month, day = map(int, birthday.split())
         birthday_date = datetime.date(today.year, month, day)
        days_until_birthday = (birthday_date - today).days

        if days_until_birthday == 0:
             message = f"Today is {name}'s birthday! 🎉"  # Message to be printed
             speak("Birthday notification")
             notification.notify(
                title='Birthday Notification',
                message=message,
                app_icon="C:\\Users\\Arnav\\OneDrive\\Documents\\cake.ico",
                app_name='Birthday Reminder',
                timeout=10,
            )     
def add_birthday():
    month = int(input("Enter the month (1-12): "))
    day = int(input("Enter the day (1-31): "))
    name = input("Enter the name: ")
    db_connection = mysql.connector.connect(**DB_CONFIG)
    cursor = db_connection.cursor()
    db_connection.commit()
    db_connection.close()
    birthdays = load_birthdays()
    birthday_key = f'{month:02d} {day:02d}'
    birthdays[birthday_key] = name
    with open(BIRTHDAYS_FILE, 'w') as file:
        json.dump(birthdays, file)
    print("Birthday added successfully!")
engine=pyttsx3.init('sapi5')
voices=engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)
def speak(audio):
    engine.say(audio)
    engine.runAndWait()
if __name__ == "__main__":
    
    while True:
        choice = input("Enter '1' to add a birthday or '2' to check for upcoming birthdays (q to quit): ")
        if choice == '1':
            add_birthday()
        elif choice == '2':
            schedule_notifications()
            schedule_notifications()
        elif choice.lower() == 'q':
            break
