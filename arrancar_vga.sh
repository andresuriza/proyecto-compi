#!/bin/bash

# Mostrar en consola qué se está haciendo
echo "⏳ Habilitando acceso X11 para Docker..."
xhost +local:root

echo "🚀 Iniciando contenedor de PKOS..."
cd ~/Compi\ final/proyecto-compi/VM || {
  echo "❌ No se encontró la carpeta ~/Compi final/proyecto-compi/VM"
  exit 1
}

sudo docker compose up

