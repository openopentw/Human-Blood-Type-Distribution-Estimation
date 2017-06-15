import numpy as np

all_blood_type = ['ii', 'aa', 'ai', 'bb', 'bi', 'ab']
blood_table = np.array([
            [ '','i','i','a','a','a','i','b','b','b','i','a','b'],
            ['i', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['i', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['a', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['a', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['a', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['i', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['b', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['b', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['b', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['i', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['a', '', '', '', '', '', '', '', '', '', '', '', ''],
            ['b', '', '', '', '', '', '', '', '', '', '', '', ''],
        ], dtype='<U2')

for i in range(1, blood_table.shape[0]):
    for j in range(1, blood_table.shape[1]):
        blood_table[i][j] = blood_table[i][0] + blood_table[0][j]

blood_table[blood_table == 'ia'] = 'ai'
blood_table[blood_table == 'ib'] = 'bi'
blood_table[blood_table == 'ba'] = 'ab'

blood_table = blood_table[1:,1:]
# blood_table = blood_table.reshape(blood_table.shape[0] / 2, 
