import numpy as np
import matplotlib.pyplot as plt

x_orbit, y_orbit = np.loadtxt('orbitTest.txt',unpack=True, usecols=[0,1])
x_planet, y_planet = np.loadtxt('PlanetData.txt',unpack=True, usecols=[0,1])

plt.figure(num=1, figsize = (12,12))

plt.hold(True)
plt.plot(x_orbit,y_orbit, 'r')
plt.plot(x_planet,y_planet, 'b')
plt.title("""Data""")
plt.xlabel("""X Coordinate (m)""")
plt.ylabel("""Y Coordinate (m)""")
plt.legend(("""Orbit""", """Planet"""))


plt.show()