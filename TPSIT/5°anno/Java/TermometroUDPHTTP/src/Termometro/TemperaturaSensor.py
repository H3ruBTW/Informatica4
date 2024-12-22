import Adafruit_DHT
import socket
import time

# Configurazione del sensore (DHT11)
DHT_SENSOR = Adafruit_DHT.DHT22
DHT_PIN = 4  # GPIO a cui è collegato il pin DATA del DHT11 (modifica se necessario)

# Configurazione del client TCP
SERVER_IP = "LaptopHeru"  # Usa il nome host configurato per il server
SERVER_PORT = 60000     # Porta del server

# Creazione del socket TCP
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # Connessione al server TCP
    print(f"Connessione al server {SERVER_IP}:{SERVER_PORT}...")
    sock.connect((SERVER_IP, SERVER_PORT))
    print("Connessione stabilita con successo.")

    # Ciclo infinito per leggere e inviare i dati
    while True:
        # Leggi i dati dal sensore
        humidity, temperature = Adafruit_DHT.read(DHT_SENSOR, DHT_PIN)

        if temperature is not None and humidity is not None:
            # Crea il messaggio con la temperatura e l'umidità come float
            message = f"{temperature:.1f} {humidity:.1f}"
            print(f"Messaggio inviato: {message}")

            # Invia il messaggio al server (temperatura e umidità)
            sock.sendall(message.encode())
        else:
            print("Errore nella lettura del sensore. Riprovo...")

        # Aspetta 30 secondi prima della prossima lettura
        time.sleep(30)
except ConnectionError as e:
    print(f"Errore di connessione: {e}")
finally:
    # Chiude il socket alla fine
    print("Chiusura della connessione...")
    sock.close()