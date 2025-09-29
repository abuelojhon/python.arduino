import serial
import time
import matplotlib.pyplot as plt

#configurar el puerto correcto linux
arduino = serial.Serial('/dev/tyyACM0',9600,timeout=1)
time.sleep(2)

valores = []

plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(valores, label = "Luz (LDR)")
ax.set_xlabel("Muestras")
ax.set_ylabel("Valor LDR (0-1023)")
ax.legend()

try: 
    while True:
        data = arduino.readline().decode().strip()

        if data.isdigit():
            valor = int(data)
            print(f"Luz: {valor}")
            valores.append(valor)

            line.set_ydata(valores)
            line.set_xdata(range(len(valores)))
            ax.relim()
            ax.autoscale_view()
            plt.pause(0.05)

except KeyboardInterrupt:
    print("Finalizado por el usuario")
    arduino.close()