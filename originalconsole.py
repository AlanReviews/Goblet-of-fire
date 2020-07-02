# Linux:   sudo python console.py /dev/ttyACM0 Termie.ini
# Windows: python console.py COM6 Termie.ini

import sys
import time
import serial
import readline

if (len(sys.argv) < 3):
    print('Missing serial port name filename')
    print('Example: python ' + sys.argv[0] + ' COM6 Termini.ini')
    exit()

port_name = sys.argv[1]
file_name = sys.argv[2]

commands = [
    'abc',
    'def',
    'quit',
    'xmodem']

def completer(text, state):
    options = [x for x in commands if x.startswith(text)]
    try:
        return options[state]
    except IndexError:
        return None

readline.parse_and_bind("tab: complete")
readline.set_completer(completer)
readline.set_completer_delims('')

# open the serial connection
handle = serial.Serial(port = port_name, baudrate = 115200)

print('\nEnter your command below or press the TAB key for help.')
print('To exit, enter the "quit" command (without the quotes).\n')

# get initial input from keyboard
prompt = 'TCC-HST> '
# match the define in console.h
CMDLINE_SIZE = 64

while True :
    # cmd = raw_input(prompt)
    cmd = input(prompt)
    # strip off all whitespaces
    cmd = " ".join(cmd.split())
    # check the command line length
    if (len(cmd) >= CMDLINE_SIZE):
        print('Command line is too long, please try again')
        continue

    if (cmd == 'quit'):
        handle.close()
        exit()

    # send the cmd
    handle.write(cmd.encode('utf-8'))
    handle.write('\r\n'.encode('utf-8'))
    # wait a bit - 10 ms
    time.sleep(.111)

    # get the response
    response = ''
    while handle.inWaiting() > 0:
        response += (handle.read(1)).decode('utf-8')
    print(response)

    if (cmd.split(' ')[0] == 'xmodem'):
        with open(file_name, 'rb') as f:
            while True:
                c = f.read(1)
                if not c:
                    print("End of file")
                    time.sleep(.222)
                    response = ''
                    while handle.inWaiting() > 0:
                        response += (handle.read(1)).decode('utf-8')
                    print(response)
                    break
                # print("Read a character: " + c)
                handle.write(c)

'''
    # display the response
    if response != '':
        # break it into chunks
        chunks = response.split('\r\n')
        # throw away the first chunk (command echo) and the last chunk (prompt)
        for i in range(1, len(chunks) - 1):
            print(chunks[i])
'''

f.close()
handle.close()
