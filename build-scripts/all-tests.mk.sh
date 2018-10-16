#!/bin/bash

touch all-tests.mk

testTargets=$(ls ./src/tests)

printf "test: " > all-tests.mk

# Build the test target
for i in ${testTargets[*]}
do
    printf "build/tests/%s.o " $i >> all-tests.mk
done
echo "" >> all-tests.mk
echo "" >> all-tests.mk

# Build the targets in src/tests
for i in ${testTargets[*]}
do
    # Target name
    printf "build/tests/%s.o: src/tests/%s all\n" $i $i >> all-tests.mk

    # Build
    printf "\t\$(cc) -o build/tests/%s.o src/tests/%s build/GreenThreads.o \n" $i $i >> all-tests.mk

    # Run target
    printf "\t./build/tests/%s.o\n" $i >> all-tests.mk

    printf "\n" $i $i >> all-tests.mk
done
echo "" >> all-tests.mk