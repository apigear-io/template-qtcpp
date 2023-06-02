### This scripts replicates 100 times the interface given in a file 'performance_interface.module.yaml' (that is is same location as script) 
### The names are changed in a way nameNumber (the first one is name0)
### Tha file cannot have more than one interface
### Currently the file cannot contain structures

import os.path
import sys

pathIn = 'performance_interface.module.yaml'
pathOut = 'performance_interface100.module.yaml'

if not os.path.isfile(pathIn):
    print("Input file doesn't exist")
    sys.exit()




input_file = open(pathIn,'r')
output_file = open(pathOut, 'w+')

line_list = input_file.readlines();

linenumber = 0


linenumber = 0
for line in line_list:
    output_file.write(line)
    linenumber = linenumber+1
    if line.lstrip().startswith('interfaces:'):
        break
       
if linenumber >= len(line_list) or linenumber +1 >= len(line_list):
    print("no interfaces found")
    sys.exit()

interface_definition = line_list[linenumber:]
#TODO find either structs or other interface and stop there
lineWithName = interface_definition[0]
if not 'name:' in lineWithName:
    print("next line after interfaces declatartion should contain an interface with a name declared like: \"name: YourName\", but what was found is")
    print(lineWithName)
    sys.exit()
name_delimeter = 'name:'
line_with_name_split = lineWithName.split(name_delimeter)
name = line_with_name_split[1]
name = name.strip()
rest_of_interface = interface_definition[1:]

for number in range (0,100):
    output_file.write(line_with_name_split[0] +name_delimeter +" " + name + str(number) + '\n')
    output_file.writelines(rest_of_interface)
    output_file.write('\n')
    output_file.write('\n')

print("File performance_interface100.module.yaml generated")