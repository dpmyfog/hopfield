import numpy as np
import matplotlib.pyplot as plt
import os

def analyzeDescent():
    for file in os.listdir('data'):
        dataArr = np.loadtxt('data/' + file)
        plt.plot(range(len(dataArr)), dataArr)

    plt.title('Energy Descent Hopfield Network')
    plt.xlabel('Update Step')
    plt.ylabel('Energy')
    plt.show()


analyzeDescent()
    
    
