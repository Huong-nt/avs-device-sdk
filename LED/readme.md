# LED controller

## Message fomat:

#### Set led status
> TOPIC: avs/led/control
```json
{
    "timestamp": long,
    "id": "uuid",
    "action": "LISTEN|THINK|SPEAK|OFF"
}
```

## Installation:
### Step 1. Activate SPI:
- sudo raspi-config
- Go to "Interfacing Options"
- Go to "SPI"
- Enable SPI
- Exit the tool
### Step 2. Get LEDs Library
   ```sh
   pip install spidev gpiozero numpy paho-mqtt PyYAML
   sudo apt install -y mosquitto mosquitto-clients
   sudo apt install -y supervisor
   
   ```
### Run Led controler
   ```sh
   sudo cp led.conf /etc/supervisor/conf.d/
   sudo supervisorctl update
   ```