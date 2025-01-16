import pandas as pd
import matplotlib.pyplot as plt

def convert_csv_to_table(input_file, multiplier=1):
    with open(input_file, 'r') as file:
        values = [line.strip().replace('"', '').replace(',', '.') for line in file]
    float_values = [float(value) * multiplier for value in values]
    df = pd.DataFrame({'Values': float_values})
    
    return df

def plot_data(x, x_label, y, y_label, plot_size=(10, 10)):
    plt.figure(figsize=plot_size)
    plt.plot(x['Values'], y['Values'], linestyle='-', linewidth=2)
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    time = convert_csv_to_table("gas_time.csv")
    data = convert_csv_to_table("gas_data.csv", 1e-9)
    plot_data(time, "Time (s)", data, "Resistor (G$\Omega$)", (8,5))

    voltage = convert_csv_to_table("rpoly_voltage.csv")
    current = convert_csv_to_table("rpoly_current.csv", 1e3)
    plot_data(voltage, "Voltage (V)", current, "Current ($mA$)", (5,5))
    
    voltage = convert_csv_to_table("peigne_voltage.csv")
    current = convert_csv_to_table("peigne_current.csv", 1e9)
    plot_data(voltage, "Voltage (V)", current, "Current ($nA$)", (10,5))
