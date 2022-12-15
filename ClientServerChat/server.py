import socket
import threading


BUF = 1024
PORT = 12345
HOSTNAME = socket.gethostname()
SERVER = socket.gethostbyname(HOSTNAME)
FORMAT = 'utf-8'
ADDR = (SERVER, PORT)
clients = {}

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.bind(ADDR)

def client(conn, addr):
    name = conn.recv(BUF).decode(FORMAT)
    print(f"{name} ONLINE")
    welcome = f"Welcome {name}"
    conn.send(bytes(welcome,FORMAT))
    msg = f"{name} has joined the chat"
    all(bytes(msg,FORMAT))
    clients[conn]=name

    connected = True
    while connected:
        msg = conn.recv(BUF)#return value is a byte object  
        if msg == b"!quit":
            all(b"has left the chat", name+": ") 
            connected = False
        
            
        else:
            all(msg, name+": ")     
    
    conn.close()
    del clients[conn]
    print(f"{name} DISCONNECTED")
    

def all(msg, identify=""):
    for sock in clients:
        sock.send(bytes(identify,FORMAT)+msg)
      
            
def StartServer():
    soc.listen(5)
    print(f"{HOSTNAME} Listening on {SERVER}")
    while True:
        conn, addr = soc.accept()
        conn.send(bytes("Enter your name and press enter. Enter !quit to exit", FORMAT))
        thread = threading.Thread(target = client, args = (conn, addr))
        thread.start()
        


if __name__ == "__main__":
    print(f"Server is starting on {SERVER}")
    StartServer()