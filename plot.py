import matplotlib.pyplot as plt
import numpy as np
from collections import OrderedDict

file1 = open('readings.txt', 'r')
Lines = file1.readlines()

usv_unsorted = {}
cpm_unsorted = {}

for line in Lines:
    values = line.split(" ")
    if(values[0] == "usv"):
        usv_unsorted[values[1]] = values[2].rstrip('\n')
    elif(values[0] == "cpm"):
        cpm_unsorted[values[1]] = values[2].rstrip('\n')

usv_sorted = sorted(usv_unsorted.items())
cpm_sorted = sorted(cpm_unsorted.items())

usv = []
usv_time = []
cpm = []
cpm_time = []

for key, value in usv_sorted:
    usv_time.append(float(key))
    usv.append(float(value))

for key, value in cpm_sorted:
    cpm_time.append(float(key))
    cpm.append(float(value))


fig, (ax1, ax2) = plt.subplots(2)
fig.suptitle('Radation vs Time')


ax1.stem(usv_time, usv)
ax1.set_xlabel('Time (in seconds)')
ax1.set_ylabel('μSv (micro-Sieverts/hour')

ax2.stem(cpm_time, cpm)
ax2.set_xlabel('Time (in seconds)')
ax2.set_ylabel('CPM (Counts per minute)')

plt.show()
