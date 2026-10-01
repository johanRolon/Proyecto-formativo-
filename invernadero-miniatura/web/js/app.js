// Cambiar por la IP que muestre el monitor serie del ESP32
const IP_ESP32 = "http://192.168.1.100";

function actualizarDatos() {
  fetch(IP_ESP32 + "/datos")
    .then(function (respuesta) { return respuesta.json(); })
    .then(function (datos) {
      document.getElementById("temperatura").textContent = datos.temperatura;
      document.getElementById("humedadAire").textContent = datos.humedadAire;
      document.getElementById("humedadSuelo").textContent = datos.humedadSuelo;
      document.getElementById("luz").textContent = datos.luz;
    })
    .catch(function () {
      console.log("No se pudo conectar con el ESP32");
    });
}

// Alterna un dispositivo. Más adelante se puede leer su estado real.
const estados = { bomba: 0, ventilador: 0, luz: 0 };

function cambiar(dispositivo) {
  estados[dispositivo] = estados[dispositivo] === 0 ? 1 : 0;
  fetch(IP_ESP32 + "/control?dispositivo=" + dispositivo +
        "&estado=" + estados[dispositivo]);
}

actualizarDatos();
setInterval(actualizarDatos, 3000);
