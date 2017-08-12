import math
import matplotlib.pyplot as plt

def suma(N):
	a=0
	for i in range(1,N+1):
		a=a+1.0/i
	return a

x=[i for i in range (1,501)]
y=[suma(x[i]) for i in range(500)]

plt.plot(x,y,'-r')
plt.xlabel('N')
plt.ylabel('Suma Arm\'onica')
plt.show()
