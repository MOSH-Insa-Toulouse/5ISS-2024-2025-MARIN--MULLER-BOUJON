
Response from "sys get ver" command :
RN2483 1.0.5 Oct 31 2018 15:06:52

DO NOT FORGET TO RESET THE RN2483 BY PULLING THE RST PIN !

# UF Smart Devices : Partie Analogique

Impédence du capteur de gaz : plusieurs gigaohms -> il faut donc amplifier le signal.

En amplifiant on amplifie aussie le buit ! Il faut donc filtrer :
1. Filtrer le bruit hf de mesure
2. Fitlrer le bruit 50Hz
3. Filtrer l'échantillonnage de l'ADC

Ampli normal avec gros offset :

![image](https://github.com/user-attachments/assets/a544955b-39e8-4ca0-a5ec-7836f8691a66)


Ampli LT1050 très faible offset :

![image](https://github.com/user-attachments/assets/fc479fac-d6a4-454c-bda5-96964039b8b9)


Schéma ampli + filtres (en bleu) :

![image](https://github.com/user-attachments/assets/6c6dc274-dd44-4bc7-9d2a-37a7cb128c63)


Fréquence de coupure du premier filtre : 16Hz

![image](https://github.com/user-attachments/assets/8086cfb8-f343-4d78-b7ed-4f89b6e671b0)

Fréquence de coupure du deuxième filtre : 1.5Hz

![image](https://github.com/user-attachments/assets/a6863864-15cf-415b-9773-68faa4495e76)


Fréquenc de coupure du troisième filtre : 1.6kHz

![image](https://github.com/user-attachments/assets/4009a6fe-1778-4e93-a6b8-1c2830185bf3)


 
Atténuation à :
- 50Hz : 40db
- Fréquence de Shannon Nyquist (2fmax adc 15kHz) : 108dB

## Simulation avec modèle du capteur de gaz 

V = RI <=> I = 1/R V <=> I = V * G (Conductance en Siemens)

Modèle du capteur de gaz : I=V(cp,cn)*(10n+(v(gc,gn)*10n))

t=0: V(cp,cn)=0 I=V(cp,cn)*(10nS)
Si t>>1: V(gc,gn)=1 I=V(cp,cn)*(10nS+10mS)
tau=R0*C0








