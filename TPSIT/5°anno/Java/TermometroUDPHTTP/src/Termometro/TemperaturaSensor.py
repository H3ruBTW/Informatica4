import Adafruit_DHT
import socket
import time

# Configurazione del sensore (DHT11)
DHT_SENSOR = Adafruit_DHT.DHT11
DHT_PIN = 4  # GPIO a cui è collegato il pin DATA del DHT11 (modifica se necessario)

# Configurazione del client UDP
UDP_IP = "127.0.0.1"  # Loopback (localhost), usa "LaptopHeru" se hai configurato il nome host
UDP_PORT = 8765       # Porta del server

# Creazione del socket UDP
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print(f"Inizio invio dati su {UDP_IP}:{UDP_PORT}...")

# Ciclo infinito per leggere e inviare i dati
while True:
    # Leggi i dati dal sensore
    humidity, temperature = Adafruit_DHT.read(DHT_SENSOR, DHT_PIN)
    
    if temperature is not None:
        # Crea il messaggio con solo la temperatura come float
        message = f"{temperature:.1f}"
        print(f"Temperatura inviata: {message}")
        
        # Invia il messaggio al server (solo il valore float della temperatura)
        sock.sendto(message.encode(), (UDP_IP, UDP_PORT))
    else:
        print("Errore nella lettura del sensore. Riprovo...")
    
    # Aspetta 30 secondi prima della prossima lettura
    time.sleep(30)
