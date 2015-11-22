/*
jackfix - A simple program to fix jack capture auto connecting to playback on KXStudio
Created by Marty Chang 2015-8-20

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <jack/jack.h>

#include <iostream>
using namespace std;

int main(int argc , char** argv)
{
        if(argc < 3)
        {
                cout << "usage : jackfix <input port num> <output port num>" << endl;
                return 0;
        }
        int captureNum = atoi(argv[1]);
        int outputNum = atoi(argv[2]);
        char** capturePorts;
        char** outputPorts;
        jack_client_t* client;
        client =  jack_client_open("JackFix",JackNoStartServer,NULL);
        if(client == NULL)
        {
                cout << "Failed to connect to jack server. Is jack running?" << endl;
                exit(0);
        }
        capturePorts = (char**)jack_get_ports (client, NULL, NULL, JackPortIsPhysical|JackPortIsOutput);
        outputPorts = (char**)jack_get_ports (client, NULL, NULL, JackPortIsPhysical|JackPortIsInput);
        for(int i=0;i<captureNum;i++)
                for(int j=0;j<outputNum;j++)
                        jack_disconnect(client,capturePorts[i],outputPorts[j]);
        return 0;
}
