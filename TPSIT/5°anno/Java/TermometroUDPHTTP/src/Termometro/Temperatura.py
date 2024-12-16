import socket
import random
import time

# Client
def udp_client():
    server_address = ('localhost', 8765)  # Cambia 'localhost' con l'indirizzo del server Java, se diverso.

    while True:
        # Creazione del socket UDP
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # Float casuale da inviare (tra 0 e 45 con una cifra decimale)
        float_value = round(random.uniform(0, 45), 1)

        try:
            # Invio del dato al server
            message = f"{float_value:.1f}"  # Formattazione a una cifra decimale
            client_socket.sendto(message.encode(), server_address)
            print(f"Inviato: {message} al server {server_address}")
        finally:
            client_socket.close()

        # Attendi 5 secondi prima di inviare il prossimo messaggio
        time.sleep(5)

# Esegui il client per inviare i messaggi in ciclo infinito
udp_client()