#!/bin/bash -f

echo 'Starting simulation . . . '
sim-outorder -config sa1core.cfg heisman
echo 'Simulation finished, time to output data'
./parse_Stats