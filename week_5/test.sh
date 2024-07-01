#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <file_name_without_extension> <number_of_tests> <flags>"
    exit 1
fi

# Assign arguments to variables
file_name=$1
if [ -n "$2" ]; then
    num_tests=$2
else
    num_tests=$(ls -1 "$file_name" | grep -E '^[0-9]+\.in$' | wc -l)
fi

# Compile the C++ file with the specified flags
if [ $? -eq 3 ]; then
    g++ "$3" -Wall -O2 -std=c++11 "$file_name.cpp"
else
    g++ -Wall -O2 -std=c++11 "$file_name.cpp"
fi

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi
total_time=0
# Loop over each test case
for ((i=1; i<=num_tests; i++))
do  
    # Define input and output files
    input_file="$file_name/$i.in"
    expected_output_file="$file_name/$i.out"
    actual_output_file="$file_name/$i.actual.out"

    # Check if the input file exists
    if [ ! -f "$input_file" ]; then
        echo "Input file $input_file does not exist."
        continue
    fi

    # Check if the expected output file exists
    if [ ! -f "$expected_output_file" ]; then
        echo "Expected output file $expected_output_file does not exist."
        continue
    fi

    # Run the program with the input file and measure the time taken
    start_time=$(date +%s%N)
    ./a.out < "$input_file" > "$actual_output_file"
    end_time=$(date +%s%N)

    # Calculate the time taken in milliseconds
    elapsed_time=$(( (end_time - start_time) / 1000000 ))
    total_time=$((total_time+elapsed_time))

    # Calculate the difference between actual and expected output
    diff_output=$(diff "$actual_output_file" "$expected_output_file")

    # Print the results
    echo "$i: $elapsed_time ms"
    if [ -z "$diff_output" ]; then
        echo "Accepted."
    else
        echo "Rejected."
    fi
    echo "------------------------"

done
echo "Total time taken: $total_time ms"