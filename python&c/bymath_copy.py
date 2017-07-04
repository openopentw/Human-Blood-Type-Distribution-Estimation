import numpy as np

'''
a = 0.2665
b = 0.2372
o = 0.4357
ab = 0.0606

rate_a = 0.1618
rate_b = 0.00000000001
rate_a = 0.8
rate_b = 0.0001
'''

birth_rate = 0.007
death_rate = 0.006
T = 1000
PRINT = False

aa = 0.1234
bb = 0.1357
ii = 0.1235
ai = 0.2017
bi = 0.2222
ab = 0.1935

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
    print('paa','pbb', 'pii', 'pai', 'pbi', 'pab', sep='\t\t\t')
while T > 0:
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

    T -= 1

    summ = aa + bb + ii + ai + bi + ab
    paa = aa / summ
    pbb = bb / summ
    pii = ii / summ
    pai = ai / summ
    pbi = bi / summ
    pab = ab / summ

    if PRINT == True:
        print(paa, pbb, pii, pai, pbi, pab, sep='\t')

summ = aa + bb + ii + ai + bi + ab
if PRINT == True:
    print('--------------')
    print('A\t\tB\t\tO\t\tAB')
print('{:.6f}\t{:.6f}\t{:.6f}\t{:.6f}'.format((aa+ai)/summ, (bb+bi)/summ, (ii)/summ, (ab)/summ))

print('paa','pbb', 'pii', 'pai', 'pbi', 'pab', sep='\t\t\t')
print(paa, pbb, pii, pai, pbi, pab, sep='\t')
