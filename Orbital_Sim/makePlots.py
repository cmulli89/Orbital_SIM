import numpy as np
import matplotlib.pyplot as plt

#Work Set
#x_orbit, y_orbit = np.loadtxt('/users/cmullins/Orbital_SIM/Workspace/Orbital_Sim/orbitTest.txt',unpack=True, usecols=[0,1])
#x_orbit2, y_orbit2 = np.loadtxt('/users/cmullins/Orbital_SIM/Workspace/Orbital_Sim/orbitTestTwo.txt',unpack=True, usecols=[0,1])
#x_planet, y_planet = np.loadtxt('/users/cmullins/Orbital_SIM/Workspace/Orbital_Sim/PlanetData.txt',unpack=True, usecols=[0,1])

#Home Set
x_orbit, y_orbit = np.loadtxt('/home/cmulli89/workspace/Orbital_SIM/Orbital_Sim/orbitTest.txt',unpack=True, usecols=[0,1])
x_orbit2, y_orbit2 = np.loadtxt('/home/cmulli89/workspace/Orbital_SIM/Orbital_Sim/orbitTestTwo.txt',unpack=True, usecols=[0,1])
x_planet, y_planet = np.loadtxt('/home/cmulli89/workspace/Orbital_SIM/Orbital_Sim/PlanetData.txt',unpack=True, usecols=[0,1])

plt.figure(num=1,figsize = (12,12))

plt.hold(True)
plt.plot(x_orbit,y_orbit, 'r')
plt.plot(x_orbit2,y_orbit2, 'g')
plt.plot(x_planet,y_planet, 'b')
plt.title("""Data""")
plt.xlabel("""X Coordinate (m)""")
plt.ylabel("""Y Coordinate (m)""")
plt.legend(("""Orbit""", """Orbit 2""", """Planet"""))
plt.axis([-1e7, 1e7, -1e7, 1e7])

plt.show()

