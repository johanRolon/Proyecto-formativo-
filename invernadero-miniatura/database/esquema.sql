-- Base de datos del invernadero (MySQL)
CREATE DATABASE IF NOT EXISTS invernadero;
USE invernadero;

CREATE TABLE lecturas (
  id INT AUTO_INCREMENT PRIMARY KEY,
  fecha DATETIME DEFAULT CURRENT_TIMESTAMP,
  temperatura FLOAT,
  humedad_aire FLOAT,
  humedad_suelo INT,
  luz INT
);

CREATE TABLE eventos (
  id INT AUTO_INCREMENT PRIMARY KEY,
  fecha DATETIME DEFAULT CURRENT_TIMESTAMP,
  dispositivo VARCHAR(20),
  accion VARCHAR(10)
);
