import numpy as np
import matplotlib.pyplot as plt
import os

def analyzeDescent():
    for file in os.listdir('data'):
        if(file != 'hamming'):
            dataArr = np.loadtxt('data/' + file)
            plt.plot(range(len(dataArr)), dataArr)

    plt.title('Energy Descent Hopfield Network')
    plt.xlabel('Update Step')
    plt.ylabel('Energy')
    plt.show()
        

def analyzeHamming():
    hammings = np.loadtxt('data/hamming/hammingMtx')
    plt.matshow(np.transpose(hammings))
    plt.colorbar()
    plt.title('Memory Strength of Hopfield Network')
    plt.xlabel('Number of Memories')

    plt.ylabel('Fraction of bits corrupted') 
	
    plt.show()



analyzeHamming()
    
