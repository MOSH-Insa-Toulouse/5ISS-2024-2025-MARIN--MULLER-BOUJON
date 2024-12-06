
Response from "sys get ver" command :
RN2483 1.0.5 Oct 31 2018 15:06:52

DO NOT FORGET TO RESET THE RN2483 BY PULLING THE RST PIN !

# UF Smart Devices : Partie Analogique

Impédence du capteur de gaz : plusieurs gigaohms -> il faut donc amplifier le signal.

En amplifiant on amplifie aussie le buit ! Il faut donc filtrer :
1. Filtrer le bruit hf de mesure
2. Fitlrer le bruit 50Hz
3. Filtrer l'échantillonnage de l'ADC

Ampli avec gros offset :

![image](https://github.com/user-attachments/assets/a544955b-39e8-4ca0-a5ec-7836f8691a66)


Ampli LT1050 très faible offset :

![image](https://github.com/user-attachments/assets/fc479fac-d6a4-454c-bda5-96964039b8b9)


