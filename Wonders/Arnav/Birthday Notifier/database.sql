CREATE DATABASE Devops;
use devops;
CREATE TABLE birthday_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50),
    middle_name VARCHAR(50),
    last_name VARCHAR(50),
    year INT,
    month INT,
    day INT,
    sms VARCHAR(10)
);

#Run these three queries one by one in mysql 
