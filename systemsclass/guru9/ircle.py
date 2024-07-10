#!/usr/bin/env python3

import os
import socket
import ssl

# Constants
HOST = 'chat.ndlug.org'
PORT = 6697
NICK = f'ircle-{os.environ["USER"]}'

# Functions

def ircle():
    # Connect to IRC server
    ssl_socket = ssl.wrap_socket(socket.socket(socket.AF_INET, socket.SOCK_STREAM))
    ssl_socket.connect((HOST, PORT))

    ssl_stream = ssl_socket.makefile('rw')

    # Identify ourselves
    ssl_stream.write(f'USER {NICK} 0 * :{NICK}\r\n')
    ssl_stream.write(f'NICK {NICK}\r\n')
    ssl_stream.flush()

    # Join #bots channel
    ssl_stream.write(f'JOIN #bots\r\n')
    ssl_stream.flush()

    # Write message to channel
    ssl_stream.write(f"PRIVMSG #bots :Hi friends!!\r\n")
    ssl_stream.flush()

    # Read and display
    while True:
        message = ssl_stream.readline().strip()
        print(message)
        if 'it was rare' in message.lower():
            ssl_stream.write(f"PRIVMSG #bots :I was there\r\n")
            ssl_stream.flush()
        if 'gary' in message.lower():
            ssl_stream.write(f"PRIVMSG #bots :His name is gabe not gary\r\n")
            ssl_stream.flush()
        if f'PING {NICK}' in message:
            ssl_stream.write(f"PONG {NICK}\r\n")
            ssl_stream.flush()


# Main Execution

def main():
    ircle()

if __name__ == '__main__':
    main()