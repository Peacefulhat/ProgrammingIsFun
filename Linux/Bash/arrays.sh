#!/usr/bin/bash
# Declare an indexed array
myArray=("apple" "banana" "cherry")

# Access elements by index
echo "First element: ${myArray[0]}"
echo "Second element: ${myArray[1]}"
echo "Third element: ${myArray[2]}"

# Iterate over all elements
echo "All elements:"
for element in "${myArray[@]}"; do
  echo "$element"
done

# Declare an associative array
declare -A myAssocArray

# Assign values to the array
myAssocArray["name"]="John"
myAssocArray["age"]=25
myAssocArray["city"]="Example City"

# Access values using keys
echo "Name: ${myAssocArray["name"]}"
echo "Age: ${myAssocArray["age"]}"
echo "City: ${myAssocArray["city"]}"

# Loop through all keys and values
echo "All key-value pairs:"
for key in "${!myAssocArray[@]}"; do
  echo "Key: $key, Value: ${myAssocArray[$key]}"
done

