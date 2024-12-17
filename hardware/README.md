# Hardware
## LTSpice simulation

By modifying the $R_{cal1}$ resistor we can see that the maximum output voltage can go up to $5V$. The goal would be to modify this resistor value to have a maximum output of around $3.3V$:
$$a=\frac{\Delta{y}}{\Delta{x}}=\frac{y_2-y_1}{x_2-x_1}$$
$$AN: a=\frac{10k-1k}{2.1-4.94}$$
$$AN: a=-3170$$
---
$$y=-3170x+b$$
$$1000=-3170(4.94)+b$$
$$b=3170(4.94)+1000$$
$$b=16659$$
---
$$y=-3170x+16659$$
We can now calculate the resistor $R_{cal1}$ to have $3.3V$ in maximum output with the previous formula, we find:
$$-3.17\times{10^3\times{3.3V}}+16.7\times{10^3}=6.2k\Omega$$

![rcal_ok](img/rcal.png)
> Has we can see with the LTSpice simulation, we have the correct maximum voltage, it does not go further than $3.29V$ which is exactly what we wanted.
## Electronic CAD