# Proyecto 2 - Monitor de Paciente Dual
Este es un sistema que simula un monitor biomédico con tres modos de operación. Integra sensores (potenciómetro), un display de 7 segmentos, LED RGB, servomotor y un buzzer para representar condiciones fisiológicas de un paciente. 


Los distintos modos de operación son los siguientes:
* **Modo 0 - Reposo**: todas las saidas apagadas. El sistema no responde a entradas excepto al Botón 1 (cambiar de modo).
* **Modo 1 - Monitor de Frecuencia Cardíaca**: el potenciómetro simula valores entre 0 y 200 lpm. El servomotor refleja en tiempo real (0° a 180°) y el LED RGB indica el estado: amarillo (bradicardia <60 lpm), verde (normal 60-100 lpm), rojo (taquicardia 100-150 lmp) y rojo parpadeante (taquicardia severa >150 lpm). 
* **Modo 2 - Monitor de Temperatura Corporal**: el potenciómetro simula valores entre 93°F y 104°F. El LED RGB y el servomotor indican el rango (hipotermia, normal, febrícula, fiebre y fiebre alta). En condiciones críticas, se activa una alarma que puede silenciarse con el Botón 2. 
