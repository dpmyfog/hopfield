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


def analyzePics():
    corruptedFace = np.loadtxt('data/corruptedFace')
    corruptedTree = np.loadtxt('data/corruptedTree')

    corruptedFace = corruptedFace.reshape((10, 10))
    corruptedTree = corruptedTree.reshape((10, 10))

    fixedFace = np.loadtxt('data/fixedFace')
    fixedTree = np.loadtxt('data/fixedTree')

    fixedFace = fixedFace.reshape((10, 10))
    fixedTree = fixedTree.reshape((10, 10))
    
    plt.matshow(corruptedFace)
    plt.title('corrupted face')
    plt.show()

    plt.matshow(fixedFace)
    plt.title('face after updating')
    plt.show()

    plt.matshow(corruptedTree)
    plt.title('corrupted tree')
    plt.show()

    plt.matshow(fixedTree)
    plt.title('tree after updating')
    plt.show()

    

analyzePics()
    
