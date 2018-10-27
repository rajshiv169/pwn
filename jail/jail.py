#!/usr/bin/python3

flag='RCTF{}'.format('{tha7_wa5_an_3a5y_jai1l_t0_3scap3}')
motd='''Python 3.6.6 (default, Jun 27 2018, 14:44:17) 
[GCC 8.1.0] on linux
Type "help", "copyright", "credits" or "license" for more information.'''
print (motd)
while True:
    comm=input(">>> ")
    if 'cat jail.py' in comm:
        continue
    elif comm=='g1b_m3_f1a9':
        print(flag)
    else: print(eval(comm))