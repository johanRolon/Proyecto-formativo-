# Invernadero Miniatura 30 x 30 cm

Proyecto formativo SENA - Análisis y Desarrollo de Software.

Invernadero a escala controlado por un ESP32. El microcontrolador se
comunica por WiFi con una página web creada para el proyecto, y esa página
se maneja como aplicación móvil usando App Inventor.

## Cómo funciona

ESP32 (sensores y actuadores) <-> WiFi <-> Página web <-> App Inventor

## Estructura del repositorio

| Carpeta | Contenido |
|---|---|
| `docs/` | Documentación del proyecto (problema, requisitos, cronograma, diagramas) |
| `hardware/` | Lista de componentes, esquema de conexiones y fotos del montaje |
| `firmware/` | Código del ESP32 (Arduino IDE, C++) |
| `web/` | Página web (HTML, CSS y JavaScript) |
| `database/` | Script SQL con las tablas para guardar el historial |
| `app-inventor/` | Proyecto de App Inventor (.aia) y su explicación |
| `pruebas/` | Plan y resultados de pruebas |

## Autor

Johan - Aprendiz SENA, Análisis y Desarrollo de Software.
