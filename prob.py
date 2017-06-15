import pandas as pd
import numpy as np

# Parameters #
data_path = './ini.csv'
rateA = 0.5
rateB = 0.5

data = pd.read_csv(data_path)
distr = data[['O', 'A', 'B', 'AB']].values

A = data['A'][0]
B = data['B'][0]

ii = data['O'][0]
aa = A * rateA
ai = A * (1-rateA)
bb = B * rateB
bi = B * (1-rateB)
ab = data['AB'][0]

I = 2*ii + ai + bi
A = 2*aa + ai + ab
B = 2*bb + bi + ab
