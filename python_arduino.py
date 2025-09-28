import serial
import time

arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
time.sleep(2)

while True:
    cmd = input("Escribe 1 para enceder, 0 para apagar, q para salir del programa: ")

    if cmd == '1' :
        arduino.write(b'1')
        print("LED encendido")
    
    elif cmd == '0' :
        arduino.write(b'0')
        print("LED apagado")
    elif cmd == 'q' :
        print("Saliendo... !!!Gracias por usar el programa!!!")
        break
    else :
        print("Comando no valido :(")

arduino.close()
