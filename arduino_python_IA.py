import serial
import pandas as pd
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import joblib
import time
import numpy as np

#Conectar Arduino
arduino = serial.Serial('/dev/ttyACM2',9600,timeout=1)
time.sleep(2)

#Simular datos para entrenar modelo IA
np.random.seed(42);

ldr_values = np.random.randint(0,1024,200)
labels = []
for val in ldr_values:

    if val < 341:
        labels.append("Baja")
    
    elif val < 682:
        labels.append("Media")
    
    else: 
        labels.append("Alta")

df = pd.DataFrame({"ldr": ldr_values, "nivel": labels})

X = df[["ldr"]]
y = df["nivel"]

X_train, x_test, y_train, y_test = train_test_split(X,y, test_size = 0.2, random_state=42)

#entrenar modelo
model = RandomForestClassifier( n_estimators=100, random_state=42)
model.fit(X_train,y_train)

#evaluar modelo
while True:
    line =arduino.readline().decode('utf-8').strip()
    if line:
        try:
            val = int(line)
            df = pd.DataFrame([[val]], columns=["ldr"])
            pred = model.predict(df)[0]

            #enviar nivel de luz a arduino
            arduino.write(f"{pred}\n".encode())
            print(f"LDR: {val} --> Nivel de luz: {pred}")

        except:
            continue
