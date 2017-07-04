import numpy as np
import pandas as pd

data = pd.read_csv('./data.csv').drop('Year', 1).values

a = data[0,0]
b = data[0,1]
o = data[0,2]
ab = data[0,3]

rate_a = 0.0000000000001
rate_b = 0.0000000000001
# rate_a = 0.8
# rate_b = 0.0001

birth_rate = 0.007
death_rate = 0.006
T = 6
PRINT = True

aa = a * rate_a
ai = a * (1-rate_a)
bb = b * rate_b
bi = b * (1-rate_b)
ii = o
# ab = 0.06060

N = 100000000

aa *= N
bb *= N
ii *= N
ai *= N
bi *= N
ab *= N

summ = aa + bb + ii + ai + bi + ab
print('A\t\tB\t\tO\t\tAB')
print('{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}'.format((aa+ai)/summ, (bb+bi)/summ, (ii)/summ, (ab)/summ))
if PRINT == True:
    print('--------------')
    print('paa','pbb', 'pii', 'pai', 'pbi', 'pab', sep='\t\t')

error = np.zeros((T, 4))

for t in range(T):
    summ = aa + bb + ii + ai + bi + ab
    paa = aa / summ
    pbb = bb / summ
    pii = ii / summ
    pai = ai / summ
    pbi = bi / summ
    pab = ab / summ

    A = 1/2 * (2*paa + pai + pab)
    B = 1/2 * (2*pbb + pbi + pab)
    I = 1/2 * (2*pii + pai + pbi)

    aa = aa*(1-death_rate) + summ * birth_rate*A*A
    bb = bb*(1-death_rate) + summ * birth_rate*B*B
    ii = ii*(1-death_rate) + summ * birth_rate*I*I
    ai = ai*(1-death_rate) + summ * 2*birth_rate*A*I
    bi = bi*(1-death_rate) + summ * 2*birth_rate*B*I
    ab = ab*(1-death_rate) + summ * 2*birth_rate*A*B

    # T -= 1

    summ = aa + bb + ii + ai + bi + ab
    paa = aa / summ
    pbb = bb / summ
    pii = ii / summ
    pai = ai / summ
    pbi = bi / summ
    pab = ab / summ

    pa = paa + pai
    pb = pbb + pbi
    po = pii
    pab = pab
    error[t, 0] = (pa - data[t+1, 0])  ** 2 / (pa ** 2)
    error[t, 1] = (pb - data[t+1, 1])  ** 2 / (pb ** 2)
    error[t, 2] = (po - data[t+1, 2])  ** 2 / (po ** 2)
    error[t, 3] = (pab - data[t+1, 3]) ** 2 / (pab ** 2)

    if PRINT == True:
        print('{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}'.format(paa, pbb, pii, pai, pbi, pab))

summ = aa + bb + ii + ai + bi + ab
if PRINT == True:
    print('--------------')
    print('A\t\tB\t\tO\t\tAB')
print('{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}'.format((aa+ai)/summ, (bb+bi)/summ, (ii)/summ, (ab)/summ))

print('paa','pbb', 'pii', 'pai', 'pbi', 'pab', sep='\t\t')
print('{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}'.format(paa, pbb, pii, pai, pbi, pab))

rms_error = np.sqrt(np.mean(error))
print('ERROR = {}'.format(rms_error))
