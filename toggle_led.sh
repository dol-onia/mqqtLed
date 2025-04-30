#!/bin/bash

BROKER="34.94.22.125"
TOPIC="ledControl"

echo "Starting LED toggle script..."

for i in {1..3}
do
    echo "[Cycle $i] LED ON"
    mosquitto_pub -h "$BROKER" -t "$TOPIC" -m "ON"
    sleep 10

    echo "[Cycle $i] LED OFF"
    mosquitto_pub -h "$BROKER" -t "$TOPIC" -m "OFF"
    sleep 10
done

echo "Done toggling LED for 1 minute."
